#include <ncurses.h>

class Tank{
    public:
        Tank(WINDOW * win,int X,int Y);
        void go_up();
        void go_down();
        
        void change_direction(int);
        void go_left();
        void go_right();   
        void display_Tank();
        void erase_Tank();
        bool can_move(); 
       // void shot(); // to do 

    private:
        WINDOW * win;
        int X_;
        int Y_;

        int direction{};        
        const int min_Y = 2; 
        const int max_Y = 23;
        const int min_X = 2;
        const int max_X = 94;// karela xckel borderi mej                            
        const char tank_pattern_ud[2][2][6] ={{ "  |  ","[xxx]"},
                                           { "[xxx]","  |  "}
                                            };
        const char tank_pattern_lr[2][3][6] = {{"  x","--x","  x"},
                                               {"x","x--","x"}
                                               };
};          


