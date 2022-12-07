#include "map.hpp"

void Map::fill_matrix(){
    add_boundaries();
    add_walls();
}

// Matrix Map::get_matrix(){
//     return game_matrix;
// }

void Map::add_boundaries(){
    game_matrix[0].assign(width,1); // top
    for(int i = 1;i<height-1;++i){ 
        game_matrix[i][0] = 1;         //left
        game_matrix[i][width-1] = 1;   //right
    }
    game_matrix[height-1].assign(width,1); //bottom
}

void Map::add_walls(){
    for(auto i :walls){
        game_matrix[i.first][i.second] = 2;
    }    
};