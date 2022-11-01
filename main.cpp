#include <ncurses.h>
#include "Game/game.cpp"

int main(){

    initscr();    
    noecho();
    curs_set(0);
    
    Tank_Game gm;
    
    while(gm.is_playing()){
        gm.process_input(); 
        gm.update();
    };

    endwin();

    return 0;
}