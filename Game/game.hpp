#pragma once
#include <ncurses.h>
#include "../Tank/tank.hpp"
#include "../Map/map.hpp"

class Tank_Game
{
private:                                                   
    bool playing;
    WINDOW * game_win;
    Map game_map;
    Tank tank_1;
    
public:
    Tank_Game();
    ~Tank_Game();  

    Matrix get_matrix();
    WINDOW * get_game_window();

    bool is_playing();
    //void update();
    void end_game();

    friend class Controller;
    friend class View;
};

