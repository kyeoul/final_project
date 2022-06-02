#include "controller.hxx"

Controller::Controller(ge211::Dims<int> screen_dims)
        : model_(screen_dims),
          view_(model_),
          screen_dims(screen_dims)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

ge211::Dims<int>
Controller::initial_window_dimensions() const{
    return screen_dims;
}

void
Controller::on_key(ge211::Key key)
{
    if(key == ge211::Key::code('w')){
        model_.move_player_vertically(-10);
    }
    else if(key == ge211::Key::code('a')){
        model_.move_player_horizontally(-10);
    }
    else if(key == ge211::Key::code('s')){
        model_.move_player_vertically(10);
    }
    else if (key == ge211::Key::code('d')){
        model_.move_player_horizontally(10);
    }
}
