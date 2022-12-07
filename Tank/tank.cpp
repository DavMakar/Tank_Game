#include "tank.hpp"
#include "bullet.hpp"

bool Tank::can_move(const Matrix& map){
    switch (direction)
    {
    case Directions::UP:
        return !(map[Y_-2][X_]);
    case Directions::DOWN:
        return !(map[Y_+2][X_]);
    case Directions::LEFT:
        return !(map[Y_+1][X_-1] || map[Y_][X_-4]|| map[Y_-1][X_-1]);
    case Directions::RIGHT:
        return !(map[Y_][X_+4] || map[Y_-1][X_+1]|| map[Y_+1][X_+1]);
    default:
        return true;   
    }
}

void Tank::display_Tank(){
    for(int i= -1 ;i<2 ;++i){ 
        mvwprintw(win,Y_ + i,X_-1,tank_pattern[direction][i+1]);
    } 
};

void Tank::erase_Tank(){
    for(int i= -1 ;i<2 ;++i){ 
        mvwprintw(win,Y_ + i,X_-1,"   ");
    }
};

void Tank::shot(Matrix & map){
    Bullet * bullet = new Bullet(win,X_,Y_,direction);
    bullet->move(map);
    delete bullet;
}

void Tank::move(Directions new_direction , const Matrix& map){
    if(new_direction != direction){
        change_direction(new_direction);
    }
    else if(can_move(map)){
        erase_Tank();
        switch (direction)
        {
            case Directions::UP:
                Y_-=1;
                break;
            case Directions::DOWN:
                Y_+=1;
                break;
            case Directions::LEFT:
                X_-=1;
                break;
            case Directions::RIGHT:
                X_+=1;
                break;
            default:
                break;
        }
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
 