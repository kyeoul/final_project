#include "view.hxx"

View::View(Model const& model)
        : model_(model),
          player_sprite(model_.get_player().get_box().dimensions(), {0, 255,
                                                                     0}),
          enemy_sprite({50, 50}, {255, 0, 0})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(player_sprite, model_.get_player().get_box().top_left());

    for (Enemy enemy: model_.get_list_enemies()){
        set.add_sprite(enemy_sprite, enemy.get_box().top_left());
    }
}
