#include "character.hxx"

Character::Character(int health, Dims size, Posn position)
    : health_(health),
      bounding_box_(size.width, size.height, position.x, position.y),
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