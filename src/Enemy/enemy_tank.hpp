#ifndef ENEMY_TANK_HPP
#define ENEMY_TANK_HPP

#include "../Game_object/tank.hpp"

class Enemy_tank
        :public Tank{
    public:
        const char enemy_pattern[4][3][6] =  {{" | ","xox","   "},
                                              {"   ","xox"," | "},
                                              {"  x","--o","  x"},
                                              {"x  ","o--","x  "}};
    public:
        Enemy_tank(int Y,int X): Tank(Y,X){};
        void action(const Matrix & );
        void move(const Matrix &);
        void reset_YX();
};

#endif //ENEMY_TANK_HPP