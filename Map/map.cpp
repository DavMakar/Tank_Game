#include "map.hpp"

Map::Map(int height,int width){
    this->height = height;
    this->width = width;    
};

void Map::fill_matrix(){
    add_boundaries();
    add_walls();
}

Matrix Map::get_matrix(){
    return game_map;
}

void Map::add_boundaries(){
    game_map[0].assign(width,1); // top
    for(int i = 1;i<height-1;++i){ 
        game_map[i][0] = 1;         //left
        game_map[i][width-1] = 1;   //right
    }
    game_map[height-1].assign(width,1); //bottom
}

void Map::add_walls(){
    for(auto i :walls){
        game_map[i.first][i.second] = 2;
    }    
};