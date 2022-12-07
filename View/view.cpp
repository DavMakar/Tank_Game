#include "view.hpp"

View::View(Tank_Game & game_model):game_model_(game_model)
{};

void View::draw_map(){
    Matrix game_matrix = game_model_.get_matrix();
    WINDOW * gm_win = game_model_.get_game_window();
    box(gm_win, 0, 0);
    wrefresh(gm_win);

    game_model_.tank_1.display_Tank();
    
    for(int i = 1 ; i<game_matrix.size()-1;++i){
        for(int j = 1;j< game_matrix[0].size()-1;++j){
            if(game_matrix[i][j] == 2){
                mvwaddch(gm_win,i,j,ACS_CKBOARD);  
            }
        }
    }
};

void View::draw_tank(){
    game_model_.tank_1.erase_Tank();
    game_model_.tank_1.display_Tank();
}

void View::update(){
    draw_tank();
}


// TODO remove from Tank display and erase, add here

// void Draw::draw_tank(WINDOW * gm_win){
//     int x = game_model_.tank_1.get_x();
//     int y = game_model_.tank_1.get_y();
//     int direction = game_model_.tank_1.get_direction();

//     for(int i= -1 ;i<1 ;++i){
//             mvwprintw(gm_win,y + i,x,tank_pattern[direction][i+1]);
//     };
// }
// void Draw::erase_tank(WINDOW * gm_win){
//     int x = game_model_.tank_1.get_x();
//     int y = game_model_.tank_1.get_y();
//     int direction = game_model_.tank_1.get_direction();

//     for(int i= -1 ;i<1 ;++i){ 
//             mvwprintw(gm_win,y + i,x,tank_pattern[direction][i+1]);
//     };
// }

