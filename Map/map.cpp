#include "map.hpp"
#include "../Adds/my_random.hpp"

void Map::fill_matrix(){
    add_boundaries();
    add_walls();
    make_tank(player_tank.get_y(),player_tank.get_x());
    make_enemy(enemy_tank.get_y(),enemy_tank.get_x());
}

void Map::add_boundaries(){
    game_matrix[0].assign(width,Map_title::boundary); // top
    for(int i = 1;i<height-1;++i){ 
        game_matrix[i][0] = Map_title::boundary;         //left
        game_matrix[i][width-1] = Map_title::boundary;   //right
    }
    game_matrix[height-1].assign(width, Map_title::boundary); //bottom
}

void Map::add_walls(){
    for(int i = 0;i<wall_count;++i){
        auto wall = random_wall();
        game_matrix[wall.first][wall.second] = Map_title::wall;
    }
};

void Map::update(){
    for(int i = 1;i<height-1;++i){
        for(int j = 1;j<width-1;++j){
            if(is_moveable_object(game_matrix[i][j])){
                make_empty(i,j);
            }
        }
    }
    
    enemy_tank.action(game_matrix);
    
    make_tank(player_tank.get_y(),player_tank.get_x());
    make_enemy(enemy_tank.get_y(),enemy_tank.get_x());
    
    if(player_tank.Bullets.size()>0){
        for(auto bullet = player_tank.Bullets.begin(); bullet != player_tank.Bullets.end();){
            auto y = (*bullet)->get_y();
            auto x = (*bullet)->get_x();
            if((*bullet)->is_hit_boundary()){
                delete (*bullet); 
                bullet = player_tank.Bullets.erase(bullet);
            }else{
                if(game_matrix[y][x] == Map_title::wall){
                    delete (*bullet); 
                    bullet = player_tank.Bullets.erase(bullet);
                    make_empty(y,x);
                }else if(bullet_collision_tank(x,y,(*bullet)->hit_box_size, enemy_tank.get_x(),enemy_tank.get_y(),enemy_tank.hit_box_size))
                {  
                    delete (*bullet); 
                    bullet = player_tank.Bullets.erase(bullet);
                    make_empty(y,x);
                 
                    --enemy_tank.health;
                    
                    if(!(enemy_tank.is_alive())){
                        make_empty(player_tank.get_y(),player_tank.get_x());
                        break;
                    };
                }
                else{
                    (*bullet)->move(game_matrix);
                    auto new_y = (*bullet)->get_y();
                    auto new_x = (*bullet)->get_x();
                    make_bullet(new_y,new_x);
                    ++bullet;
                }
            }   
        }
    };
    if(enemy_tank.Bullets.size()>0){
        for(auto bullet = enemy_tank.Bullets.begin(); bullet != enemy_tank.Bullets.end();){
            auto y = (*bullet)->get_y();
            auto x = (*bullet)->get_x();
            if((*bullet)->is_hit_boundary()){
                delete (*bullet); 
                bullet = enemy_tank.Bullets.erase(bullet);
            }else{
                (*bullet)->move(game_matrix);
                auto new_y = (*bullet)->get_y();
                auto new_x = (*bullet)->get_x();
                if(game_matrix[new_y][new_x] == Map_title::wall){
                    delete (*bullet); 
                    bullet = enemy_tank.Bullets.erase(bullet);
                    make_empty(new_y,new_x);
                }
                else if(bullet_collision_tank(new_x,new_y,(*bullet)->hit_box_size, player_tank.get_x(),player_tank.get_y(),player_tank.hit_box_size))
                { 
                    delete (*bullet); 
                    bullet = enemy_tank.Bullets.erase(bullet);
                    make_empty(new_y,new_x);

                    --player_tank.health;
                    if(!(player_tank.is_alive())){
                        make_empty(player_tank.get_y(),player_tank.get_x());
                        break;
                    };
                }
                else{
                    make_bullet(new_y,new_x);
                    ++bullet;
                }
            }   
        }
    };
}

bool Map::bullet_collision_tank(int bullet_x,int bullet_y,const int bullet_size , int tank_x ,int tank_y ,const int tank_size){
    bool collision_X = (bullet_x <= tank_x) && (bullet_x > tank_x - tank_size);
    bool collision_Y = (bullet_y <= tank_y) && (bullet_y > tank_y - tank_size);

    return collision_X && collision_Y;
}

bool Map::is_moveable_object(const int matrix_elem){
    if (matrix_elem == Map_title::player || matrix_elem == Map_title::bullet || matrix_elem == Map_title::enemy){
        return true;
    }
    else{
        return false;
    }
}


void Map::make_tank(const int Y ,const int X){
    game_matrix[Y][X] = Map_title::player;
}

void Map::make_empty(const int Y,const int X){
    game_matrix[Y][X] = Map_title::empty;
}

void Map::make_bullet(const int Y,const int X){
    game_matrix[Y][X] = Map_title::bullet;
}

void Map::make_enemy(const int Y,const int X){
    game_matrix[Y][X] = Map_title::enemy;
}

Matrix Map::get_matrix(){
    return game_matrix;
}