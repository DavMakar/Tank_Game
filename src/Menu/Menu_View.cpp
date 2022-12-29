#include "Menu_View.hpp"
#include <ncurses.h>

Menu_View::Menu_View(Menu_Model &menu_model):menu_model_{menu_model}{
    //start_color();
    //init_pair(1,COLOR_RED,-1); 
};

void Menu_View::render(){
    
    auto options = menu_model_.options;
    for(int i = 0 ; i < options.size() ; ++i){
        WINDOW * button_win = newwin(Button_params::height,Button_params::width,Button_params::pos_y+Button_params::space*i,Button_params::pos_x);
        box(button_win,0,0);
        if(menu_model_.current_selection == i){
            //wattron(button_win,COLOR_PAIR(1));
            mvwprintw(button_win,1,2," | ");
            mvwprintw(button_win,2,2,"XXX");
            mvwprintw(button_win,2,9,options[i].data());
            mvwprintw(button_win,1,20," | ");
            mvwprintw(button_win,2,20,"XXX");
            wrefresh(button_win);
            //wattroff(button_win,COLOR_PAIR(1));
        }
        else{
            mvwprintw(button_win,2,9,options[i].data());
        }
        wrefresh(button_win);
    }
}