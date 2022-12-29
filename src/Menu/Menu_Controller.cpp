#include "Menu_Controller.hpp"
#include <ncurses.h>

Menu_Controller::Menu_Controller(Menu_Model & menu_model,Menu_View & menu_view)
                            :menu_model_{menu_model},
                            menu_view_{menu_view}
{};

void Menu_Controller::menu_loop(){
    in_main_menu = true;
    allow_to_start = false;
    while (in_main_menu){
        menu_view_.render();
        process_input();
    }
}
void Menu_Controller::process_input()
{
    auto key = getch();
    switch(key){
        case Menu_controls::UP:
            if(menu_model_.current_selection == 0){
                menu_model_.current_selection = menu_model_.options.size()-1;
            }else{
                --menu_model_.current_selection; 
            }
            break;
        case Menu_controls::DOWN:
            menu_model_.current_selection =(menu_model_.current_selection + 1)%(menu_model_.options.size());
            break;
        case Menu_controls::SELECT:
            if(menu_model_.current_selection == 0){
                in_main_menu = false;
                allow_to_start = true;
            }else if(menu_model_.current_selection == 3){
                in_main_menu = false;
                allow_to_start = false;
            }
        default:
            break;
    }
}
