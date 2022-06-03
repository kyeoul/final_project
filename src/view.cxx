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
          health_sprite(15, {255, 0, 0})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    if (!model_.is_player_invuln()){
        set.add_sprite(player_sprite, model_.get_player().get_box().top_left()
        .into<int>());
    }
    else{
        set.add_sprite(player_damaged_sprite, model_.get_player().get_box()
        .top_left().into<int>());
    }

    for (Enemy enemy: model_.get_list_enemies()){
        set.add_sprite(enemy_sprite,
                       enemy.get_box().top_left().into<int>());
    }

    for (Bullet bullets: model_.get_bullets()){
        set.add_sprite(bullet_sprite, bullets.get_center().into<int>());
    }

    ge211::Text_sprite::Builder letter_builder(sans30);
    letter_builder << "score: " << model_.get_score();
    score_sprite.reconfigure(letter_builder);
    set.add_sprite(score_sprite, {10, 10});

    for (int i = 0; i < model_.get_player().get_health(); i++){
        set.add_sprite(health_sprite, {10 + 35 * i, 60});
    }
}
