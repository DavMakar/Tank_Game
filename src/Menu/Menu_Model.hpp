#ifndef MENU_MODEL_HPP
#define MENU_MODEL_HPP

#include <vector>
#include <string>

using button_name = std::string;
using buttons_list = std::vector<button_name>;

class Menu_Model
{
public:
    buttons_list options;
    int current_selection;

public:
    Menu_Model(buttons_list options);
    void set_selection(int selection);
};

#endif //MENU_MODEL_HPP
