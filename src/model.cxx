#include "model.hxx"

Model::Model(ge211::Dims<int> screen_dims)
    : player(3,
             Dimensions(player_width, player_height),
             Position((screen_dims.width - player_width)/2,
                      (screen_dims.height - player_height)/2)),
      screen_dims(screen_dims),
      current_aim(0, 0),
      random_x_coor_(0, screen_dims.width - player_width),
      random_speed_(50, 100)
{

    for(int i = 0; i < 10; i++){
        spawn_enemy();
    }
}

void
Model::spawn_enemy()
{
    ge211::Posn<double> candidate_position = {(double) random_x_coor_.next(),
                                              (double) player_height};

    ge211::Posn<float> position_float = candidate_position.into<float>();
    // while (candidate_position.x < screen_dims.width && candidate_position.x >
    //         0){
    //     candidate_position.x = random_x_coor_.next();
    // }
    //
    // while (candidate_position.y < screen_dims.height && candidate_position.y
    // > 0){
    //     candidate_position.y = random_y_coor_.next();
    // }

    int speed = random_speed_.next();

    Dimensions velocity = {player.get_box().center().x -
                                candidate_position.x, player.get_box().center()
                                .y
                                - candidate_position.y};

    double magnitude = std::sqrt(pow(velocity.width, 2) + pow(velocity
            .height, 2));
    ge211::Dims<double> unit_velocity = velocity / magnitude;

    ge211::Dims<double> enemy_velocity = unit_velocity * speed;

    list_enemies.push_back(Enemy(2, {50, 50},
                                 candidate_position, enemy_velocity));
}

void
Model::on_frame(double dt)
{
    if (player.check_live()){

        for(Enemy& enemy: list_enemies){

            if (hits_top(enemy.get_box()) || hits_bottom(enemy.get_box())){
                enemy.reflect_vert();
            }
            else if (hits_side(enemy.get_box())){
                enemy.reflect_horiz();
            }
            else if(player.is_colliding(enemy.get_box())){
                if (player_invuln_timer > 100) {
                    player.increment_health(-1);
                    if (!player.check_live()) {
                        exit(3);
                    }
                    player_invuln_timer = 0;
                }
            }

            player_invuln_timer++;

            for(Bullet& bullet: bullets)
            {

                if(enemy.is_colliding(bullet.get_bounding_box())){
                    enemy.increment_health(-1);
                    if (!enemy.check_live()){
                        enemy = list_enemies.back();
                        list_enemies.pop_back();
                    }
                    bullet = bullets.back();
                    bullets.pop_back();
                }
                else if(hits_bottom(bullet.get_bounding_box()) ||
                        hits_top(bullet.get_bounding_box()) ||
                        hits_side(bullet.get_bounding_box())){
                    bullet = bullets.back();
                    bullets.pop_back();
                }

                bullet = bullet.next(dt);
            }
            enemy.move_enemy(dt);
        }

        if (list_enemies.empty()){
            for(int i = 0; i < 10; i++){
                spawn_enemy();
            }
        }
    }
}

Player
Model::get_player() const
{
    return player;
}

std::vector<Enemy>
Model::get_list_enemies() const
{
    return list_enemies;
}

std::vector<Bullet>
Model::get_bullets() const
{
    return bullets;
}

bool Model::is_player_invuln() const
{
    return player_invuln_timer < 100;
}

void
Model::move_player_horizontally(int x){
    ge211::Rect<double> bounding_box = player.get_box();

    if (x < 0 && bounding_box.top_left().x + x > 0){
        player.move_player_horizontally(x);
    }
    if (x > 0 && bounding_box.top_right().x + x < screen_dims.width){
        player.move_player_horizontally(x);
    }
}

void
Model::move_player_vertically(int y)
{
    ge211::Rect<double> bounding_box = player.get_box();

    if (y < 0 && bounding_box.top_left().y + y > 0){
        player.move_player_vertically(y);
    }
    if (y > 0 && bounding_box.bottom_left().y + y < screen_dims.height){
        player.move_player_vertically(y);
    }
}

bool
Model::hits_top(ge211::Rect<double> block)
{
    return block.top_left().y < 0;
}

bool
Model::hits_bottom(ge211::Rect<double> block)
{
    return block.bottom_left().y > screen_dims.height;
}

bool
Model::hits_side(ge211::Rect<double> block)
{
    if (block.top_left().x > 0 && block.top_right().x < screen_dims.width){
        return false;
    }
    return true;
}

void
Model::move_aim(ge211::Posn<int> position)
{
    Dimensions player_to_mouse = position
            .into<double>() - player.get_box().center();

    double vec_magnitude = sqrt(pow(player_to_mouse.width, 2) + pow
            (player_to_mouse.height, 2));

    current_aim = player_to_mouse / vec_magnitude;
}

void
Model::fire_bullet()
{
    Bullet new_bullet(player.get_box().center(), 200 * current_aim, 10);
    bullets.push_back(new_bullet);
}
