#include "bullet.hpp"
//#include <unistd.h>

Bullet::Bullet(int y,int x,int dir):game_object(y,x){
    direction = dir;
};

bool Bullet::is_hit_boundary(){
    return hit;
}

void Bullet::move(const Matrix & matrix){
    switch (direction)
    {
    case Directions::UP:
        if(Y_>1){
            --Y_;
        }
        else{
            hit = true;
        }
        break;
    case Directions::DOWN:
        if ( Y_< (matrix.size()-2))
        { 
            ++Y_;
        }
        else{
            hit = true;
        }
        break;
    case Directions::LEFT:
        if (X_ > 1)
        { 
            --X_;
        }
        else{
            hit = true;
        }
        break;
    case Directions::RIGHT:
        if (X_< (matrix[0].size()-2))
        { 
            ++X_;
        }
        else{
            hit = true;
        }
        break;
    default:
        break;
    }
}