#include "character.hxx"

Character::Character(int health, Dims size, Posn position)
    : health_(health),
      bounding_box_(position.x, position.y, size.width, size.height),
      is_live_(true)
{

}

void
Character::increment_health(int change)
{
    health_ += change;

    if (health_ <= 0){
        is_live_ = false;
    }
}

Character::Rect
Character::get_box()
{
    return bounding_box_;
}

int
Character::get_health()
{
    return health_;
}

bool
Character::check_live() const
{
    return is_live_;
}

// As with the edge collision functions, we want to use the ball's
// bounding box. That is, the box whose top is center.y - radius, whose
// left is center.x - radius, whose bottom is center.y + radius, and
// whose right is center.x + radius.
//
// That way, we are checking for the intersection of two rectangles.
//
// One way to think of that is that the rectangles *don't* intersect if
// either of these is true:
//
//  - The right side of one rectangle is to the left of the left side of
//  the other.
//
//  - The bottom of one rectangle is above the top of the other
//
// Otherwise, they do.
//
bool
Character::is_colliding(Character::Rect object1)
{
    if(object1.top_right().x < bounding_box_.top_left().x ||
       bounding_box_.top_right().x < object1.top_left().x ||
       object1.bottom_left().y < bounding_box_.top_left().y ||
       bounding_box_.bottom_left().y < object1.top_left().y){
        return false;
    }
    return true;
}

Player::Player(int health, Dims size, Posn pos):
        Character(health, size, pos)
{

}

void
Player::move_player_horizontally(int x)
{
    bounding_box_.x += x;
}

void
Player::move_player_vertically(int y)
{
    bounding_box_.y += y;
}

Player::Rect
Player::get_box()
{
    return Character::get_box();
}

int
Player::get_health()
{
    return Character::get_health();
}

bool
Player::check_live() const
{
    return Character::check_live();
}

bool
Player::is_colliding(Rect object1)
{
    return Character::is_colliding(object1);
}

void
Player::increment_health(int change)
{
    Character::increment_health(change);
}

Enemy::Enemy(int health, Dims size, Posn pos, Dims velocity):
       Character(health, size, pos),
       velocity_(velocity)
{}

Enemy::Rect
Enemy::get_box()
{
    return Character::get_box();
}

bool
Enemy::check_live() const
{
    return Character::check_live();
}

void Enemy::move_enemy(double dt)
{
    bounding_box_.x += velocity_.width * dt;
    bounding_box_.y += velocity_.height * dt;
}

void Enemy::reflect_horiz()
{
    velocity_.width *= -1;
}

void Enemy::reflect_vert()
{
    velocity_.height *= -1;
}

bool
Enemy::is_colliding(Rect object1)
{
    return Character::is_colliding(object1);
}

void
Enemy::increment_health(int change)
{
    Character::increment_health(change);
}

Assists::Assists(
        Dims size,
        Posn position,
        int bullet_multiple,
        int health_increase):
        Character(1, size, position),
        bullet_multiple(bullet_multiple),
        health_increase(health_increase)
{}

std::pair<int, int>
Assists::get_benefits()
{
    return std::make_pair(bullet_multiple, health_increase);
}

Character::Rect
Assists::get_box()
{
    return Character::get_box();
}

void
Assists::increment_health(int change)
{
    Character::increment_health(change);
}