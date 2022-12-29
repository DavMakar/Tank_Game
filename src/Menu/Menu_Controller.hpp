#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

#include "Menu_Model.hpp"
#include "Menu_View.hpp"

class Menu_Controller
{
private:
    Menu_Model & menu_model_;
    Menu_View & menu_view_;
    bool in_main_menu = true;

    enum Menu_controls{
        UP = 'w',
        DOWN = 's',
        SELECT = 'j'
    };

public:
    bool allow_to_start = false;
public:
    Menu_Controller(Menu_Model & , Menu_View &);
    void process_input();
    void menu_loop();
};

#endif //MENU_CONTROLLER_HPP