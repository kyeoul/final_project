#include "proj.hxx"

Bullet
Bullet::next(double dt) const
{
    Bullet result(*this);
    result.center.x = result.center.x + (dt * result.velocity.width);
    result.center.y = result.center.y + (dt * result.velocity.height);
    return result;
}