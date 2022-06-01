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

void
Character::move_player_horizontally(int x)
{
    bounding_box_.x += x;
}

void
Character::move_player_vertically(int y)
{
    bounding_box_.y += y;
}

Character::Rect
Character::get_box()
{
    return bounding_box_;
}

bool
Character::check_dead() const
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