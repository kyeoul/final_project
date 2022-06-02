#include "view.hxx"

View::View(Model const& model)
        : model_(model),
          player_sprite(model_.get_player().get_box().dimensions(), {255, 0, 0})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(player_sprite, model_.get_player().get_box().top_left());
}
