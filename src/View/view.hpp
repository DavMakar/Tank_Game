#ifndef VIEW_HPP
#define VIEW_HPP

#include <vector>
#include "../Game/game.hpp"
#include "../Menu/Menu_View.hpp"

class View{
    private:
        Game & game_model_;
        //WINDOW * menu_win_;
    public: 
        WINDOW * game_win_;
        Menu_View menu_view_;
        
    public:
        View(Game &);
        void draw_game_scene();
        void render();
        void end_screen();

    private:
        void display_healths();
        void draw_empty(int,int);
        void draw_wall(int,int);
        void draw_bullet(int,int);
        void draw_enemy(int,int);
        void draw_player(int,int);
        void game_over_screen();
        void game_win_screen();
};

#endif //VIEW_HPP