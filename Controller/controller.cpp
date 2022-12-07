#include <unordered_map> 
#include "controller.hpp"

void make_header();

Controller::Controller()
{
    initscr();
    noecho();
    curs_set(0);
    make_header();
    refresh();
}


enum Move_controls{
    UP_KEY = 'w',
    DOWN_KEY = 's',
    LEFT_KEY = 'a',
    RIGHT_KEY = 'd'
};

void Controller::process_Input(Tank_Game &Game){
    auto key = wgetch(Game.game_win);
    switch(key){
        case Move_controls::UP_KEY:
            Game.tank_1.move(Directions::UP,Game.game_map.game_matrix);
            break;
        case Move_controls::DOWN_KEY:
            Game.tank_1.move(Directions::DOWN,Game.game_map.game_matrix);
            break;
        case Move_controls::LEFT_KEY:
            Game.tank_1.move(Directions::LEFT,Game.game_map.game_matrix);
            break;
        case Move_controls::RIGHT_KEY:
            Game.tank_1.move(Directions::RIGHT,Game.game_map.game_matrix);
            break;
        case 'q':
            Game.end_game();
            break;
        case 'j':
            Game.tank_1.shot(Game.game_map.game_matrix);
            break;
        default:
            break;
    }
}

void make_header(){
    mvprintw(0,10,"___________              __       ________                       ");
    mvprintw(1,10,"\\__    ___/____    ____ |  | __  /  _____/_____    _____   ____  ");
    mvprintw(2,10,"  |    |  \\__  \\  /    \\|  |/ / /   \\  ___\\__  \\  /     \\_/ __ \\ ");
    mvprintw(3,10,"  |    |   / __ \\|   |  \\    <  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ ");
    mvprintw(4,10,"  |____|  (____  /___|  /__|_ \\  \\______  (____  /__|_|  /\\___  >");
    mvprintw(5,10,"               \\/     \\/     \\/         \\/     \\/      \\/     \\/ ");
}
