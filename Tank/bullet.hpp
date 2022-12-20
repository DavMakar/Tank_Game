#pragma once
#include <vector>
#include "../Game_object/game_object.hpp"

class Bullet
        :public game_object{
    private:
        bool hit = false;
    public:
        const int hit_box_size = 1;
    public:
        Bullet(int y,int x,int dir);
        void move(const Matrix &);
        bool is_hit_boundary();
        bool detect_collision(const Matrix &);
};

