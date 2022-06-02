#pragma once

#include <ge211.hxx>

class Character
{
public:

    using Dims = ge211::Dims<int>;

    using Posn = ge211::Posn<int>;

    using Rect = ge211::Rect<int>;

    Character(int health, Dims size, Posn position);

    void increment_health(int change);

    bool check_live() const;

    bool is_colliding(Rect object1);

    Rect get_box();

protected:
    int health_;
    Rect bounding_box_;
    bool is_live_;
};

class Player: Character
{
public:
    using Dims = ge211::Dims<int>;

    using Posn = ge211::Posn<int>;

    using Rect = ge211::Rect<int>;

    Player(int health, Dims size, Posn pos);

    void move_player_horizontally(int x);

    void move_player_vertically(int y);

    Rect get_box();
    bool check_live() const;
};

class Enemy: Character
{
public:
    using Dims = ge211::Dims<int>;

    using Posn = ge211::Posn<int>;

    using Rect = ge211::Rect<int>;

    Enemy(int health, Dims size, Posn pos, Dims velocity);

    Rect get_box();
    bool check_live() const;

    void move_enemy(double dt);
private:
    Dims velocity_;
};