#include "game.hpp"

Game::Game() :  playing{true},
                game_map{Map_params::height, Map_params::width}              
{                    
    game_map.fill_matrix();   
}

bool Game::is_playing()
{
    return playing;
}
void Game::update(){
    game_map.update();
    if(!(game_map.enemy_tank.is_alive())){
        end_game();
        win = true;
    }else if(!(game_map.player_tank.is_alive())){
        end_game();
        game_over = true;
    }
}

void Game::set_default(){
    playing = true;
    win = false;
    game_over = false;

    game_map.enemy_tank.reset();
    game_map.player_tank.reset();
    game_map.fill_matrix();
}

bool Game::is_lose(){
    return game_over;
}
bool Game::is_win(){
    return win;
}
void Game::end_game()
{
    playing = false;
}

Game::~Game()
{
    endwin();
}

