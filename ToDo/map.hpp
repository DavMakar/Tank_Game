/*#include <ncurses.h>

class Map{
    public:
        Map();
        WINDOW* get_map();
    private:
        WINDOW *win;
        const int height{25};
        const int width{100};
        const int win_y = 10;
        const int win_x = 10;    
};

Map::Map(){ 
    WINDOW * win =newwin(height,width,win_y,win_x);
    refresh();
    box(win,0,0);
    wrefresh(win);
}

WINDOW* Map::get_map(){
    return win;
}*/