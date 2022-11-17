#include <map> 
#include "controller.hpp"

using Controls = std::map<char,int>;

Controls move_controls{{'w',0},{'s',1},{'a',2},{'d',3}};

void Controller::process_Input(Tank_Game &Game){
    auto key = wgetch(Game.game_win);
    const auto it = move_controls.find(key);
    if(it != move_controls.end()){
        Game.tank_1.change_direction(it->second);
        if(Game.tank_1.can_move(Game.game_map.get_matrix())){
            Game.tank_1.move();
        };         
    };
    if(key == 'q'){
        Game.end_game();
    };
}