#ifndef MAP_HPP
#define MAP_HPP

#include "../Player/player_tank.hpp"
#include "../Enemy/enemy_tank.hpp"
#include <vector>

using Wall = std::vector<std::pair<int,int>>;
using Matrix = std::vector<std::vector<int>>;

class Map{
    private:
        int height;
        int width;
        const int wall_count = 25;
        enum Tank_coords { player_starting_y = 10 , player_starting_x = 10 , enemy_starting_y = 10 , enemy_starting_x = 90};

    public:
        enum Matrix_cell_type{empty = 0, boundary = 1, player = 1 , wall = 2,  bullet = 3, enemy = 4}; 
    public: 
        Matrix game_matrix;
        Player_tank player_tank;
        Enemy_tank enemy_tank;
    
    public:
        Map(int height,int width)
                    :height{height}, width{width},
                    game_matrix{Matrix(height,std::vector<int>(width))},
                    player_tank{Tank_coords::player_starting_y,Tank_coords::player_starting_x},
                    enemy_tank{Tank_coords::enemy_starting_y,Tank_coords::enemy_starting_x}
        {} 
        void fill_matrix();

        Matrix get_matrix();

        void update();
        
        void make_tank(const int Y,const int X);
        void make_empty(const int Y,const int X);
        void make_bullet(const int Y ,const int X);
        void make_enemy(const int Y,const int X);
        void reset();

    private:
        bool bullet_collision_tank(const int bullet_x,const int bullet_y,const int bullet_size ,
                                    const int tank_x ,const int tank_y ,const int tank_size);
        void handle_bullets(std::vector<Bullet*>& bullets, Tank& currentTank, Tank& otherTank);
        bool is_moveable_object(const int matrix_ceil);
        bool is_wall(const int matrix_element);
        void add_boundaries();
        void add_walls();
};

#endif // MAP_HPP
