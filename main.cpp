#include "Controller/controller.hpp"
//#include "Draw/draw.hpp"
//#include "Game/game.hpp"

int main(){

    Tank_Game::init();
    Tank_Game gm;

    while(gm.is_playing()){
        Controller::process_Input(gm);
        gm.update();
    };

    return 0;
}