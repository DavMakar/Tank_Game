#ifndef TANK_CLASS_HPP
#define TANK_CLASS_HPP

#include <vector>
#include "game_object.hpp"
#include "bullet.hpp"


using Matrix = std::vector<std::vector<int>>;

class Tank 
    : public Game_object{
        
    public:
        std::vector <Bullet*> Bullets; 
        int health = 1;
        const int hit_box_size = 3;
        bool alive = false;

    public:
        Tank(int Y,int X);

        virtual void move(Directions new_direction, const Matrix& map);
        void shot();
        void reset();
        void unload_bullets();
        bool is_destroyed();
        
    protected:
        void change_direction(int);
        bool can_move(const Matrix& map);
        void move_in_current_direction();
};          

#endif //TANK_CLASS_HPP
