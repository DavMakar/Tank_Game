#include "map.hpp"
#include "../libs/my_random.hpp"

void Map::fill_matrix(){
    add_boundaries();
    add_walls();
    make_tank(player_tank.get_y(),player_tank.get_x());
    make_enemy(enemy_tank.get_y(),enemy_tank.get_x());
}

void Map::reset(){
    enemy_tank.reset_YX();
    player_tank.reset_YX();
    for(auto i = 0; i < game_matrix.size(); ++i)
        fill(game_matrix[i].begin(),game_matrix[i].end(),0);
}

void Map::add_boundaries(){
    game_matrix[0].assign(width,Matrix_cell_type::boundary); // top
    for(int i = 1 ; i < height-1 ; ++i){ 
        game_matrix[i][0] = Matrix_cell_type::boundary;         //left
        game_matrix[i][width-1] = Matrix_cell_type::boundary;   //right
    }
    game_matrix[height-1].assign(width, Matrix_cell_type::boundary); //bottom
}

void Map::add_walls(){
    for(int i = 0 ; i < wall_count ; ++i){
        auto wall = random_wall();
        game_matrix[wall.first][wall.second] = Matrix_cell_type::wall;
    }
};

void Map::update(){
    for(int i = 1; i < height-1 ; ++i){
        for(int j = 1 ; j < width-1 ; ++j){
            if(is_moveable_object(game_matrix[i][j])){
                make_empty(i,j);
            }
        }
    }
    
    enemy_tank.action(game_matrix);
    
    make_tank(player_tank.get_y(),player_tank.get_x());
    make_enemy(enemy_tank.get_y(),enemy_tank.get_x());
    
    if(!player_tank.Bullets.empty()){
        for(auto bullet = player_tank.Bullets.begin(); bullet != player_tank.Bullets.end();){
            auto y = (*bullet)->get_y();
            auto x = (*bullet)->get_x();
            
            if((*bullet)->is_hit_boundary()){
                delete (*bullet); 
                bullet = player_tank.Bullets.erase(bullet);
            }else if(is_wall(game_matrix[y][x])){
                delete (*bullet); 
                bullet = player_tank.Bullets.erase(bullet);
                make_empty(y,x);
            }else if(bullet_collision_tank(x,y,(*bullet)->hit_box_size, enemy_tank.get_x(),enemy_tank.get_y(),enemy_tank.hit_box_size)){
                delete (*bullet); 
                bullet = player_tank.Bullets.erase(bullet);
                make_empty(y,x);
                 
                --enemy_tank.health;
                    
                if(enemy_tank.is_destroyed()){
                    make_empty(player_tank.get_y(),player_tank.get_x());
                    break;
                };
            }else{
                (*bullet)->move(game_matrix);
                make_bullet(y,x);
                ++bullet;
            }
        }
    };
    if(!enemy_tank.Bullets.empty()){
        for(auto bullet = enemy_tank.Bullets.begin(); bullet != enemy_tank.Bullets.end();){
            auto y = (*bullet)->get_y();
            auto x = (*bullet)->get_x();
            if((*bullet)->is_hit_boundary()){
                delete (*bullet); 
                bullet = enemy_tank.Bullets.erase(bullet);
            }else if(is_wall(game_matrix[y][x])){
                delete (*bullet); 
                bullet = enemy_tank.Bullets.erase(bullet);
                make_empty(y,x);
            }else if(bullet_collision_tank(x,y,(*bullet)->hit_box_size, player_tank.get_x(),player_tank.get_y(),player_tank.hit_box_size)){ 
                delete (*bullet); 
                bullet = enemy_tank.Bullets.erase(bullet);
                make_empty(y,x);

                --player_tank.health;
                
                if(player_tank.is_destroyed()){
                    make_empty(player_tank.get_y(),player_tank.get_x());
                    break;
                };
            }
            else{
                (*bullet)->move(game_matrix);
                make_bullet(y,x);
                ++bullet;
            }
        }   
    };
}

bool Map::bullet_collision_tank(const int bullet_x ,const int bullet_y ,const int bullet_size,
                                const int tank_x ,const int tank_y ,const int tank_size){
    bool collision_X = (bullet_x <= tank_x) && (bullet_x > tank_x - tank_size);
    bool collision_Y = (bullet_y <= tank_y) && (bullet_y > tank_y - tank_size);

    return collision_X && collision_Y;
}

bool Map::is_moveable_object(const int matrix_cell){
    return (matrix_cell == Matrix_cell_type::player || matrix_cell == Matrix_cell_type::bullet 
            || matrix_cell == Matrix_cell_type::enemy);
}
bool Map::is_wall(const int matrix_cell){
    return matrix_cell == Matrix_cell_type::wall;
}
void Map::make_tank(const int Y ,const int X){
    game_matrix[Y][X] = Matrix_cell_type::player;
}
void Map::make_empty(const int Y,const int X){
    game_matrix[Y][X] = Matrix_cell_type::empty;
}
void Map::make_bullet(const int Y,const int X){
    game_matrix[Y][X] = Matrix_cell_type::bullet;
}
void Map::make_enemy(const int Y,const int X){
    game_matrix[Y][X] = Matrix_cell_type::enemy;
}

Matrix Map::get_matrix(){
    return game_matrix;
}