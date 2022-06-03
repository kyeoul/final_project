#pragma once

#include <ge211.hxx>

class Character
{
public:

    using Dims = ge211::Dims<double>;

    using Posn = ge211::Posn<double>;

    using Rect = ge211::Rect<double>;

    Character(int health, Dims size, Posn position);

    virtual void increment_health(int change);

    virtual bool check_live() const;

    virtual bool is_colliding(Rect object1);

    virtual Rect get_box();

    virtual int get_health();

protected:
    int health_;
    Rect bounding_box_;
    bool is_live_;
};

class Player: Character
{
public:
    using Dims = ge211::Dims<double>;

    using Posn = ge211::Posn<double>;

    using Rect = ge211::Rect<double>;

    Player(int health, Dims size, Posn pos);

    void move_player_horizontally(int x);

    void move_player_vertically(int y);

    Rect get_box();
    int get_health();

    bool check_live() const;

    bool is_colliding(Rect object1);

    void increment_health(int change);
};

class Enemy: Character
{
public:
    using Dims = ge211::Dims<double>;

    using Posn = ge211::Posn<double>;

    using Rect = ge211::Rect<double>;

    Enemy(int health, Dims size, Posn pos, Dims velocity);

    Rect get_box();
    bool check_live() const;

    void move_enemy(double dt);

    void reflect_vert();
    void reflect_horiz();

    bool is_colliding(Rect object1);

    void increment_health(int change);
private:
    Dims velocity_;
};