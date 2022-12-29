#include "enemy_tank.hpp"
#include "../libs/my_random.hpp"

void Enemy_tank::action(const Matrix & matrix){
    auto die = roll_die();
    if(die <= 3){
        move(matrix);
    }
    else if(die == 5){
        change_direction(random_direction());
    }
    else if(die == 8){
        if(Bullets.empty()){
            shot();
        }
    }
}

void Enemy_tank::move(const Matrix & matrix){
    if(!(can_move(matrix))){
        change_direction(random_direction());
    }else{
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
}

void Enemy_tank::reset_YX(){
    reset();
    Y_ = 10;
    X_ = 90;
}
