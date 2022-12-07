#include "game.hpp"

Tank_Game::Tank_Game() : playing{true},
                         game_map{25, 100},
                         game_win{newwin(25, 100, 10, 10)},
                         tank_1{game_win, 15, 10}
{
    game_map.fill_matrix();
}

Matrix Tank_Game::get_matrix(){
    return game_map.game_matrix;
};

WINDOW * Tank_Game::get_game_window(){
    return game_win;
};

// void Tank_Game::update(){
//     wrefresh(game_win);
// };

bool Tank_Game::is_playing()
{
    return playing;
}

void Tank_Game::end_game()
{
    playing = false;
}

Tank_Game::~Tank_Game()
{
    endwin();
}

