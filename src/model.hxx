#pragma once

#include <ge211.hxx>
#include "character.hxx"

class Model
{

public:

    using Rectangle = ge211::Rect<int>;

    using Dimensions = ge211::Dims<int>;

    using Position = ge211::Posn<int>;

    void move_player_horizontally(int x);

    void move_player_vertically(int y);

    void move_player_to_center(Dimensions);

    Character get_player() const;



    explicit Model();

    int player_width = 100;

    int player_height = 100;
private:

    Character player;

};
