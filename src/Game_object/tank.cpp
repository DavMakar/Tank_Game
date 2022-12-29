#include "tank.hpp"
#include "bullet.hpp"

Tank::Tank(int Y,int X):Game_object(Y,X){
    alive = true;
}

bool Tank::is_destroyed(){
    if(health == 0){
        alive = false;
    }
    return !alive;
}

void Tank::reset(){
    health = 1;
    alive = true;
}

bool Tank::can_move(const Matrix& map){
    switch (direction)
    {
    case Directions::UP:
        return !(map[Y_-3][X_] || map[Y_-3][X_-1] || map[Y_-3][X_-2]);
    case Directions::DOWN:
        return !(map[Y_+1][X_] || map[Y_+1][X_-1] || map[Y_+1][X_-2]);
    case Directions::LEFT:
        return !(map[Y_-1][X_-3] || map[Y_-2][X_-3] || map[Y_][X_-3]);
    case Directions::RIGHT:
        return !(map[Y_][X_+1] || map[Y_-1][X_+1] || map[Y_-2][X_+1]);
    default:
        return true;   
    }
}

void Tank::unload_bullets(){
    if(!Bullets.empty()){
        Bullets.clear();
    };
}

void Tank::shot(){
    switch (direction)
    {
    case Directions::UP:
        Bullets.push_back(new Bullet(Y_-3,X_-1,direction));
        break;
    case Directions::DOWN:
        Bullets.push_back(new Bullet(Y_+1,X_-1,direction));
        break;
    case Directions::LEFT:
        Bullets.push_back(new Bullet(Y_-1,X_-3,direction));
        break;
    case Directions::RIGHT:
        Bullets.push_back(new Bullet(Y_-1,X_+1,direction));
        break;
    default:
        break;
    }
}

void Tank::move(Directions new_direction , const Matrix& matrix){
    if(new_direction != direction){
        change_direction(new_direction);
    }
    else if(can_move(matrix)){
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

void Tank::change_direction(int d){
    direction = d;
};
 