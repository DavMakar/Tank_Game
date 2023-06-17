#include "game.hpp"

Game::Game():game_map{Map_params::height, Map_params::width}              
{                    
    game_map.fill_matrix();   
}

bool Game::is_playing()
{
    return playing;
}
void Game::update(){
    game_map.update();
    
    if(game_map.enemy_tank.is_destroyed()){
        end_game();
        you_win = true;
    }else if(game_map.player_tank.is_destroyed()){
        end_game();
        game_over = true;
    }
}

void Game::set_default(){
    playing = true;
    you_win = false;
    game_over = false;

    game_map.reset();
    game_map.enemy_tank.unload_bullets();
    game_map.player_tank.unload_bullets();
    game_map.fill_matrix();
}

bool Game::is_lose(){
    return game_over;
}
bool Game::is_win(){
    return you_win;
}
void Game::end_game()
{
    playing = false;
}
void Game::start_game(){
    playing = true;
}

Game::~Game()
{
    endwin();
}

