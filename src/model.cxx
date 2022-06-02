#include "model.hxx"

Model::Model(ge211::Dims<int> screen_dims)
    : player(3,
             Dimensions(player_width, player_height),
             Position((screen_dims.width - player_width)/2,
                      (screen_dims.height - player_height)/2)),
      screen_dims(screen_dims),
      random_x_coor_(-player_width, screen_dims.width + player_width),
      random_y_coor_(-player_height, screen_dims.height + player_height),
      random_speed_(5, 10)
{

    for(int i = 0; i < 10; i++){
        spawn_enemy();
    }
}

void
Model::spawn_enemy()
{
    ge211::Posn<int> candidate_position = {random_x_coor_.next(),
                                         random_y_coor_.next
                                   ()};

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

    float speed = random_speed_.next();

    Dimensions velocity = {player.get_box().center().x -
                                candidate_position.x, player.get_box().height
                                - candidate_position.y};

    ge211::Dims<float> velocity_float = velocity.into<float>();
    float magnitude = std::sqrt(velocity.width^2 + velocity.height^2);
    ge211::Dims<float> unit_velocity = velocity_float / magnitude;

    ge211::Dims<float> enemy_velocity = unit_velocity * speed;

    list_enemies.push_back(Enemy(2, {50, 50},
                                 candidate_position, enemy_velocity.into<int>
                                         ()));
}

void
Model::on_frame(double dt)
{
    if (player.check_live()){
        for(Enemy& enemy: list_enemies){
            enemy.move_enemy(dt);
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

void
Model::move_player_horizontally(int x){
    player.move_player_horizontally(x);
}

void
Model::move_player_vertically(int y)
{
    player.move_player_vertically(y);
}