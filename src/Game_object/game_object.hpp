#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

enum Directions {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
};

class Game_object
{
    protected:
        int Y_;
        int X_;
        int direction{};
    public:
        const int hit_box_size = 1;
    public:
        Game_object(int Y,int X):Y_{Y},X_{X}{};
        int get_y();
        int get_x();
        int get_direction();
};
#endif //GAME_OBJECT_HPP