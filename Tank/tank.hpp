#include <ncurses.h>

class Tank{
    public:
        Tank(WINDOW * win,int X,int Y);
        int get_y();
        int get_x();
        int get_direction();

        void move();        
        bool can_move(auto& map);

        void display_Tank();
        void erase_Tank();

        void change_direction(int);

    private:
        WINDOW * win;
        int X_;
        int Y_;
        
        int direction{};
                           
        const char tank_pattern_ud[2][2][6] ={{ "  |  ","[xxx]"},
                                           { "[xxx]","  |  "}
                                            };
        const char tank_pattern_lr[2][3][6] = {{"  x","--x","  x"},
                                               {"x","x--","x"}
                                               };
};          


