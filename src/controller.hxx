#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();

    void on_key(ge211::Key) override;

protected:
    void draw(ge211::Sprite_set& set) override;

private:
    Model model_;
    View view_;
};
