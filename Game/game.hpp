#ifndef TANK_GAME_HPP
#define TANK_GAME_HPP

#include <ncurses.h>

#include "../Map/map.hpp"
#include "../Menu/Menu_Model.hpp"

class Game
{
private:
    bool playing = false;
    bool win = false;
    bool game_over = false;

    //WINDOW *game_win;
    Map game_map;

    
public:
    Game();
    ~Game();
    
    enum Map_params
    {
        height = 25,
        width = 100,
        pos_x = 10,
        pos_y = 10
    };

    Menu_Model menu_model_{std::vector<std::string>{"Play", "Options", "HowToPlay", "Quit"}};

    Matrix get_matrix();
    //WINDOW *get_game_window();

    bool is_playing();
    bool is_lose();
    bool is_win();
    void set_default();
    void update();
    void end_game();

private:
    void update_bullets();

    friend class Controller;
    friend class View;
};

#endif // TANK_GAME_HPP