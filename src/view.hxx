#pragma once

#include "model.hxx"

class View : ge211::Abstract_game
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    ge211::Dims<int> initial_window_dimensions() const override;
private:

    Model const& model_;

    ge211::Dims<int> screen_dim;

    ge211::sprites::Rectangle_sprite player_sprite;
};
