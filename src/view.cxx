#include "view.hxx"

View::View(Model const& model)
        : model_(model),
          screen_dim({1024, 720}),
          player_sprite(model_.get_player().get_box().dimensions(), {255, 0, 0})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(player_sprite, model_.get_player().get_box().top_left());
}

ge211::Dims<int>
View::initial_window_dimensions() const{
    return screen_dim;
}
