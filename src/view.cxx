#include "view.hxx"
#include "model.hxx"

View::View(Model const& model)
        : model_(model),
          player_sprite({100, 100}, {0, 255,
                                                                     0}),
          player_damaged_sprite({100, 100}, {255, 255,
                                             0}),
          enemy_sprite({50, 50}, {255, 0, 0}),

          bullet_sprite(10, {0, 0, 255})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    if (model_.timer > 100){
        set.add_sprite(player_sprite, model_.get_player().get_box().top_left()
                                            .into<int>());
    }
    else{
        set.add_sprite(player_damaged_sprite, model_.get_player().get_box()
        .top_left()
                                            .into<int>());
    }

    for (Enemy enemy: model_.get_list_enemies()){
        set.add_sprite(enemy_sprite, enemy.get_box().top_left().into<int>());
    }

    for (Bullet bullets: model_.get_bullets()){
        set.add_sprite(bullet_sprite, bullets.get_center().into<int>());
    }
}
