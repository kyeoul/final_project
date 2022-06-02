#pragma once

#include <ge211.hxx>

class Bullet
{
public:

    using Position = ge211::Posn<int>;

    using Velocity = ge211::Dims<int>;

    Bullet(Position position, Velocity velocity);

    Position center;

    Velocity velocity;

    Bullet next(double dt) const;
};