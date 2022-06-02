#pragma once

#include <ge211.hxx>

class Bullet
{
public:

    using Position = ge211::Posn<double>;

    using Velocity = ge211::Dims<double>;

    Bullet(Position position, Velocity velocity, int radius);

    Bullet next(double dt) const;

    Position get_center();

    ge211::Rect<double> get_bounding_box();

private:
    Position center;

    int radius;

    Velocity velocity;
};