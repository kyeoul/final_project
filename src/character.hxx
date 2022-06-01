#pragma once

#include <ge211.hxx>

class Character
{
public:

    using Dims = ge211::Dims<int>;

    using Posn = ge211::Posn<int>;

    using Rect = ge211::Rect<int>;

    Character(int health, Dims size, Posn position);

    void move_player_horizontally(int x);

    void move_player_vertically(int y);

    void increment_health(int change);

    Rect get_box();

    virtual bool check_dead() const;

    bool is_colliding(Rect object1);

protected:
    int health_;
    Rect bounding_box_;
    bool is_live_;
};