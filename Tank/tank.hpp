#include <vector>
#include "../Game_object/game_object.hpp"


class Tank 
        : public game_object{
    private:
        int direction{};                           
        const char tank_pattern[4][3][6] =   {{" | ","xxx","   "},
                                              {"   ","xxx"," | "},
                                              {"  x","--x","  x"},
                                              {"x  ","x--","x  "}};
    public:
        Tank(WINDOW * win,int X,int Y):game_object(win,X,Y){};
        int get_y();
        int get_x();
        int get_direction();

        void move(Directions new_direction,const Matrix& map);
        void shot(Matrix & map);    
        void display_Tank();
        void erase_Tank();

    private:
        void change_direction(int);
        bool can_move(const Matrix & map);
};          


