#ifndef MENU_VIEW_HPP
#define MENU_VIEW_HPP

#include "Menu_Model.hpp"

class Menu_View
{
private:
    Menu_Model & menu_model_;
    
    enum Button_params{
        height = 5,
        width = 25,
        pos_y = 10,
        pos_x = 55,
        space = 5
    };

public:
    Menu_View(Menu_Model &);
    void render();
};

#endif //MENU_VIEW_HPP
