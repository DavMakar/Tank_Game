#include <ncurses.h>
#include "tank.cpp"

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

Tank_Game::Tank_Game() : playing{true},
                         game_win{newwin(25, 100, 10, 10)},
                         p1{game_win, 15, 10}
{
    refresh();
    box(game_win, 0, 0);
    wrefresh(game_win);
    p1.display_Tank();
}

void Tank_Game::process_input()
{
    auto key = wgetch(game_win);
    if (key == 's')
    {
        p1.change_direction(1);
        p1.go_down();
    }
    if (key == 'w')
    {
        p1.change_direction(0);
        p1.go_up();
    }
    if (key == 'a')
    {
        p1.change_direction(2);
        p1.go_left();
    }
    if (key == 'd')
    {
        p1.change_direction(3);
        p1.go_right();
    }
    if (key == 'x')
    {
        playing = false;
    }
}

void Tank_Game::update(){
    wrefresh(game_win);
}

bool Tank_Game::is_playing(){
    return playing;
}
