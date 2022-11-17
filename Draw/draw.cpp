// #include "draw.hpp"

// void Draw::draw_map(Tank_Game & game_model){
//     Matrix game_matrix = game_model.game_map.get_matrix();
//     WINDOW *gm_win = game_model.get_game_window();

//     for(int i = 1 ; i<game_matrix.size()-1;++i){
//         for(int j = 1;j< game_matrix[0].size()-1;++j){
//             if(game_matrix[i][j] == 2){
//                 mvwprintw(gm_win,i,j,"[]");  
//             }
//         }
//     }
// };