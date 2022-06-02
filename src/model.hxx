#pragma once

#include <ge211.hxx>
#include "character.hxx"
#include "proj.hxx"

class Model
{

public:

    using Rectangle = ge211::Rect<int>;

    using Dimensions = ge211::Dims<int>;

    using Position = ge211::Posn<int>;

    Model(Dimensions screen_dims);

    void move_player_horizontally(int x);

    void move_player_vertically(int y);

    void spawn_enemy();

    std::vector<Bullet> bullets;

    std::vector<Bullet> get_bullets() const;

    void fire_bullet();

    std::vector<Enemy> get_list_enemies() const;

    void on_frame(double dt);

    Player get_player() const;

    int player_width = 100;

    int player_height = 100;
private:

    Player player;

    std::vector<Enemy> list_enemies;

    Dimensions screen_dims;

    ge211::Random_source<int> random_x_coor_;
    ge211::Random_source<int> random_y_coor_;
    ge211::Random_source<int> random_speed_;
};
