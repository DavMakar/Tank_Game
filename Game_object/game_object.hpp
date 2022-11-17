#include <ncurses.h>

class game_object
{
protected:
    int X_;
    int Y_;
    int direction;
    WINDOW * win;

public:
     game_object(WINDOW *,int,int);
    ~game_object();
};

game_object::game_object(WINDOW * win,int X,int Y)
{
    X_ = X;
    Y_ = Y;
    this->win = win;  
}

