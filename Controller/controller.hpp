#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "../Game/game.hpp"
#include "../View/view.hpp"
#include "../Menu/Menu_Controller.hpp"

class Controller
{
    private:
        Game & game_model_;
        View & game_scene_;
        
        enum Move_controls{
            UP_KEY = 'w',
            DOWN_KEY = 's',
            LEFT_KEY = 'a',
            RIGHT_KEY = 'd'
        };    
    public:
        Menu_Controller menu_controller_;

    public:
        Controller(Game & , View &);
        void game_loop();
        void process_Input();
};

#endif //GAME_CONTROLLER