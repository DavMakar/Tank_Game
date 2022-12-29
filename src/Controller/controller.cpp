#include "controller.hpp"
#include <chrono>
#include <unistd.h> //usleep



Controller::Controller(Game & game_model, View & game_scene)
                           :game_model_{game_model},
                            game_scene_{game_scene},
                            menu_controller_{game_model_.menu_model_,game_scene_.menu_view_}
{}

void Controller::game_loop(){

    menu_controller_.menu_loop();
    
    if(menu_controller_.allow_to_start){
        game_model_.start_game();
        game_scene_.draw_game_scene();    

        while(game_model_.is_playing()){
           
            process_input();
            game_model_.update();
            game_scene_.render();

            delay(); 
        };
        
        game_scene_.end_screen();
        game_model_.set_default();
        game_loop();
    }
}

void Controller::process_input(){
    auto key = wgetch(game_scene_.game_win_);
    handle_input(key);
}

void Controller::handle_input(auto key){
    switch(key){
        case Move_controls::UP_KEY:
            game_model_.game_map.player_tank.move(Directions::UP,game_model_.game_map.get_matrix());
            break;
        case Move_controls::DOWN_KEY:
            game_model_.game_map.player_tank.move(Directions::DOWN,game_model_.game_map.get_matrix());
            break;
        case Move_controls::LEFT_KEY:
            game_model_.game_map.player_tank.move(Directions::LEFT,game_model_.game_map.get_matrix());
            break;
        case Move_controls::RIGHT_KEY:
            game_model_.game_map.player_tank.move(Directions::RIGHT,game_model_.game_map.get_matrix());
            break;
        case Move_controls::FORCE_QUIT_KEY:
            game_model_.end_game();
            break;
        case Move_controls::SHOT_KEY:
            game_model_.game_map.player_tank.shot();
            break;
        default:
            break;
    }
}

void Controller::delay(){
    usleep(delay_time);
}