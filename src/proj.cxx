#include "proj.hxx"

Bullet::Bullet(Position position, Velocity velocity, int radius):
        center(position),
        radius(radius),
        velocity(velocity)
{}

Bullet::Position
Bullet::get_center()
{
    return center;
}

ge211::Rect<double>
Bullet::get_bounding_box()
{
    ge211::Rect<double> return_box = {center.x - radius, center.y - radius,
                                      (double) 2*radius, (double) 2*radius};
    return return_box;
}

Bullet
Bullet::next(double dt) const
{
    Bullet result(*this);
    result.center.x = result.center.x + (dt * result.velocity.width);
    result.center.y = result.center.y + (dt * result.velocity.height);
    return result;
}