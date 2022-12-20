#include "Menu_Controller.hpp"
#include <ncurses.h>

Menu_Controller::Menu_Controller(Menu_Model & model,Menu_View & view):model{model},view{view}{
};

void Menu_Controller::menu_loop(){
    in_main_menu = true;
    allow_to_start = false;
    while (in_main_menu){
        view.render();
        process_input();
    }
}
void Menu_Controller::process_input()
{
    auto key = getch();
    switch(key){
        case Menu_controls::UP:
            if(model.current_selection == 0){
                model.current_selection = model.options.size()-1;
            }else{
                --model.current_selection; 
            }
            break;
        case Menu_controls::DOWN:
            model.current_selection =(model.current_selection + 1)%(model.options.size());
            break;
        case Menu_controls::SELECT:
            if(model.current_selection == 0){
                in_main_menu = false;
                allow_to_start = true;
            }else if(model.current_selection == 3){
                in_main_menu = false;
                allow_to_start = false;
            }
        default:
            break;
    }
}
