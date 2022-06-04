#pragma once

#include "model.hxx"

class View : ge211::Abstract_game
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set) override;
private:

    Model const& model_;

    ge211::sprites::Rectangle_sprite player_sprite;
    ge211::sprites::Rectangle_sprite player_damaged_sprite;
    ge211::sprites::Rectangle_sprite enemy_sprite;
    ge211::sprites::Rectangle_sprite enemy_damaged_sprite;
    ge211::sprites::Circle_sprite bullet_sprite;
    ge211::sprites::Circle_sprite powerup_sprite;
    ge211::sprites::Image_sprite heart_sprite;

    ge211::Font sans30{"sans.ttf", 30};
    ge211::Text_sprite score_sprite;
};
