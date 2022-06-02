#include "model.hxx"

Model::Model(ge211::Dims<int> screen_dims)
    : player(3,
             Dimensions(player_width, player_height),
             Position((screen_dims.width - player_width)/2,
                      (screen_dims.height - player_height)/2)),
      screen_dims(screen_dims),
      random_x_coor_(-player_width, screen_dims.width + player_width),
      random_y_coor_(-player_height, screen_dims.height + player_height),
      random_speed_(-5, 5)
{}

Player
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