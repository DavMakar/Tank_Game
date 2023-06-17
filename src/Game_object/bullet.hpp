#ifndef BULLET_HPP
#define BULLET_HPP
#include <vector>
#include "game_object.hpp"

using Matrix = std::vector<std::vector<int>>;

class Bullet
        :public Game_object{
    private:
        bool hit = false;
    public:
        Bullet(int y,int x,int dir);
        void move(const Matrix &);
        bool is_hit_boundary();    
};
#endif //BULLET_HPP