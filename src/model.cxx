#include "model.hxx"

Model::Model()
    : player(3, Dimensions(player_width, player_height), Position(0, 0))
{}

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