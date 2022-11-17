#include <ncurses.h>
#include "../Tank/tank.hpp"
#include "../Map/map.hpp"

class Tank_Game
{
public:
    Tank_Game();
    ~Tank_Game();  

    Matrix get_matrix();
    WINDOW * get_game_window();

    static void init();    
    void update();
    bool is_playing();
    void end_game();

private:
    bool playing;
    WINDOW * game_win;
    Map game_map;
    Tank tank_1;
    
    friend class Controller;
    friend class Draw;
};

