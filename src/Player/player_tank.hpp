#ifndef PLAYER_TANK_HPP
#define PLAYER_TANK_HPP

#include "../Game_object/tank.hpp"

class Player_tank
        :public Tank{
    public:
        const char player_pattern[4][3][6] = {{" | ","xxx","   "},
                                            {"   ","xxx"," | "},
                                            {"  x","--x","  x"},
                                            {"x  ","x--","x  "}};
    public:
        Player_tank(int Y , int X): Tank(Y , X){};
        void reset_YX();
};

#endif //PLAYER_TANK_HPP