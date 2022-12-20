#include "Menu_View.hpp"
#include <ncurses.h>

Menu_View::Menu_View(Menu_Model & model): model{model}{
    start_color();
    init_pair(1,COLOR_RED,-1); 
};

void Menu_View::render(){
    
    auto options = model.options;
    for(int i =0 ; i<options.size();i++){
        WINDOW * button_win = newwin(Button_params::height,Button_params::width,Button_params::pos_y+Button_params::space*i,Button_params::pos_x);
        box(button_win,0,0);
        if(model.current_selection == i){
            wattron(button_win,COLOR_PAIR(1));
            mvwprintw(button_win,2,3,options[i].data());
            wrefresh(button_win);
            wattroff(button_win,COLOR_PAIR(1));
        }
        else{
            mvwprintw(button_win,2,0,options[i].data());
        }
        
        wrefresh(button_win);
    }
}