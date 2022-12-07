#include "Controller/controller.hpp"
#include "View/view.hpp"

int main(){
    
    Controller game_controller;
    Tank_Game gm;
    View game_scene(gm);

    game_scene.draw_map();    

    while(gm.is_playing()){
        game_controller.process_Input(gm);
        //game_scene.update();                        //FIXME 
        game_scene.update();
    };

    return 0;
}