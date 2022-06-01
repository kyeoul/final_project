#include "model.hxx"

Model::Model()
    : player(3, Dimensions(player_width, player_height), Position(0, 0))
{}

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
Model::is_colliding(Rectangle object1, Rectangle object2)
{
    if(object1.top_right().x < object2.top_left().x ||
       object2.top_right().x < object1.top_left().x ||
       object1.bottom_left().y < object2.top_left().y ||
       object2.bottom_left().y < object1.top_left().y){
        return false;
    }

    return true;
}

Character
Model::get_player() const
{
    return player;
}

void
Model::move_player_horizontally(int x){
    player.move_player_horizontally(x);
}

void
Model::move_player_vertically(int y)
{
    player.move_player_vertically(y);
}