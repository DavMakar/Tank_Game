#include "bullet.hpp"
#include <unistd.h>

Bullet::Bullet(WINDOW* win,int x,int y,int dir):game_object(win,x,y){
    direction = dir;
};

void Bullet::erase(){
    mvwaddch(win,Y_,X_,' ');
}

void Bullet::display(){
    mvwaddch(win,Y_,X_,ACS_BULLET);
}

bool Bullet::detect_collision(Matrix & map){
    if (map[Y_][X_] == 2){
        map[Y_][X_] = 0;
        return true;
    };
    return false;
}

void Bullet::move(Matrix & map){   
    switch (direction)
    {
    case Directions::UP:
        Y_-=2;
        display();
        while (Y_>1)
        { 
            erase();
            --Y_;
            display();
            wrefresh(win);
            usleep(speed);   
            //TODO thread std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        break;
    case Directions::DOWN:
        Y_+=2;
        display();
        while (Y_< (map.size()-2))
        { 
            erase();
            ++Y_;
            display();
            wrefresh(win);
            usleep(speed);
        }
        break;
    case Directions::LEFT:
        X_-=2;
        display();
        while (!(detect_collision(map))||X_ > 1)
        { 
            erase();
            --X_;
            display();
            wrefresh(win);
            usleep(speed-10000);
        }
        break;
    case Directions::RIGHT:
        X_+=2;
        display();
        while (!(detect_collision(map)) && X_< (map[0].size()-2))
        { 
            erase();
            ++X_;
            display();
            wrefresh(win);
            usleep(speed-10000);
        }
        break;
    default:
        break;
    }
    erase();
}