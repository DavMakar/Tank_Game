#include <ncurses.h>
#include "../Tank/tank.cpp"

class Tank_Game
{
public:
    Tank_Game(); // init game
    bool is_playing();
    void process_input();
    void update();

private:
    bool playing = false;
    WINDOW *game_win;
    Tank p1;
};

