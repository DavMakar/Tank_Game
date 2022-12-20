#ifndef TANK_CLASS_HPP
#define TANK_CLASS_HPP

#include <vector>
#include "../Game_object/game_object.hpp"
#include "bullet.hpp"

class Tank 
    : public game_object{

    public:
        std::vector <Bullet*> Bullets; 
        int health = 1;
        const int hit_box_size = 3;
        bool alive = false;

    public:
        Tank(int Y,int X);

        void hit_bullet();
        void move(Directions new_direction, const Matrix& matrix);
        void shot();
        void reset();
        bool is_alive(); 
        void display_Tank();
        
    protected:
        void change_direction(int);
        bool can_move(const Matrix & map);
};          

#endif //TANK_CLASS_HPP
