#include "Menu_Model.hpp"

Menu_Model::Menu_Model(buttons_list options){
    this->options = options;
    current_selection = 0;
}

void Menu_Model::set_selection(int selection){
    current_selection = selection;
}