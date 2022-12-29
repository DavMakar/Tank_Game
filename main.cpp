#include "src/Controller/controller.hpp"
#include "src/View/view.hpp"

int main(){
    
    Game game;
    View game_scene(game);
    Controller game_controller(game,game_scene);
    
    game_controller.game_loop();
    
    return 0;
}