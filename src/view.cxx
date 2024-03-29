#include "view.hxx"
#include "model.hxx"

View::View(Model const& model)
        : model_(model),
          player_sprite({100, 100}, {0, 255,
                                                                     0}),
          player_damaged_sprite({100, 100}, {255, 255,
                                             0}),
          enemy_sprite({50, 50}, {255, 0, 0}),
          enemy_damaged_sprite({50, 50}, {255, 0, 255}),
          bullet_sprite(10, {0, 0, 255}),
          powerup_sprite(20, {0, 255, 255}),
          heart_sprite("heart.png")
{ }

void
View::draw(ge211::Sprite_set& set)
{
    if (!model_.is_player_invuln()){
        set.add_sprite(player_sprite, model_.get_player().get_box().top_left()
        .into<int>(), 2);
    }
    else{
        set.add_sprite(player_damaged_sprite, model_.get_player().get_box()
        .top_left().into<int>(), 2);
    }

    for (Enemy enemy: model_.get_list_enemies()){
        set.add_sprite(enemy_sprite,
                       enemy.get_box().top_left().into<int>(), 3);
    }

    for (Bullet bullets: model_.get_bullets()){

        double scale = (double) model_.get_radius() / 10.0;

        ge211::Transform my_transform = ge211::Transform{}.set_scale(scale);
        set.add_sprite(bullet_sprite, bullets.get_bounding_box().top_left()
        .into<int>(), 1, my_transform);
    }

    for (Assists assists: model_.get_assists()){

        if (assists.get_benefits().first != 0){
            set.add_sprite(powerup_sprite, assists.get_box().top_left()
            .into<int>());
        }
        else{
            double scale = 1.0/22.5;
            ge211::Transform my_transform = ge211::Transform{}.set_scale(scale);
            set.add_sprite(heart_sprite, assists.get_box().top_left().into<int>
                    (), 1, my_transform);
        }
    }

    ge211::Text_sprite::Builder letter_builder(sans30);
    letter_builder << "score: " << model_.get_score();
    score_sprite.reconfigure(letter_builder);
    set.add_sprite(score_sprite, {10, 10});

    for (int i = 0; i < model_.get_player().get_health(); i++){
        double scale = 1.0/22.5;
        ge211::Transform my_transform = ge211::Transform{}.set_scale(scale);
        set.add_sprite(heart_sprite, {10 + 35 * i, 60}, 4, my_transform);
    }
}
