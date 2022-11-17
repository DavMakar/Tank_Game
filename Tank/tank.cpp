#include "tank.hpp"

enum Directions {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
};

Tank::Tank(WINDOW * w ,int X,int Y){
    X_ = X;
    Y_ = Y;
    win = w;    
}

bool Tank::can_move(auto & map){
    switch (direction)
    {
    case Directions::UP:
        return !(map[Y_-1][X_]|| map[Y_-1][X_-1]|| map[Y_-1][X_+1]);
        break;
    case Directions::DOWN:
        return !(map[Y_+1][X_]|| map[Y_+1][X_-1]|| map[Y_+1][X_+1]);
        break;
    case Directions::LEFT:
        return !(map[Y_+1][X_-1]|| map[Y_][X_-1]|| map[Y_-1][X_-1]);
        break;
    case Directions::RIGHT:
        return !(map[Y_][X_+1]|| map[Y_-1][X_+1]|| map[Y_+1][X_+1]);
        break;
    default:
        return true;
        break;
    }
}

void Tank::display_Tank(){
    if(direction<2){
        for(int i= -1 ;i<1 ;++i){ //FIXME need change
            mvwprintw(win,Y_ + i,X_,tank_pattern_ud[direction][i+1]);
        }
    }else{
        for(int i= -1 ;i<2 ;++i){ 
            mvwprintw(win,Y_ + i,X_,tank_pattern_lr[direction-2][i+1]);
        }
    }
};

void Tank::erase_Tank(){
    for(int i= -1 ;i<2 ;++i){ 
        mvwprintw(win,Y_ + i,X_,"    ");
    }
};


void Tank::move(){
    switch (direction)
    {
    case Directions::UP:
        erase_Tank();
        Y_-=1;
        display_Tank(); 
        break;
    case Directions::DOWN:
        erase_Tank();
        Y_+=1;
        display_Tank();
        break;
    case Directions::LEFT:
        erase_Tank();
        X_-=1;
        display_Tank();
        break;
    case Directions::RIGHT:
        erase_Tank();
        X_+=1;
        display_Tank();
        break;
    default:
        break;
    }
};

int Tank::get_x(){
    return X_;
};
int Tank::get_y(){
    return Y_;
};

int Tank::get_direction(){
    return direction;
};

void Tank::change_direction(int d){
    direction = d;
};
 