#pragma once

#include <ncurses.h>

using Matrix = std::vector<std::vector<int>>;

enum Directions {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
};

class game_object
{
protected:
    int X_;
    int Y_;
    int direction;
    WINDOW * win;

public:
     game_object(WINDOW *,int,int);
};

inline game_object::game_object(WINDOW * win,int X,int Y)
{
    X_ = X;
    Y_ = Y;
    this->win = win;  
}
