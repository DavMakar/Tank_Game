#ifndef TANK_GAME_HPP
#define TANK_GAME_HPP

#include <ncurses.h>

#include "../Map/map.hpp"
#include "../Menu/Menu_Model.hpp"

class Game
{
private:
    bool playing = false;
    bool you_win = false;
    bool game_over = false;

public:
    
    Game();
    
    Map game_map;
    Menu_Model menu_model_{std::vector<std::string>{"Play", "Options", "HowToPlay", "Quit"}};
    
    enum Map_params
    {
        height = 25,
        width = 100,
        pos_x = 10,
        pos_y = 10
    };

    Matrix get_matrix();

    void start_game();
    void end_game();
    
    bool is_playing();

    bool is_lose();
    bool is_win();

    /**
     * @brief Set the default object
     * 
     */
    void set_default();
    void update();
    
    ~Game();

};

#endif // TANK_GAME_HPP