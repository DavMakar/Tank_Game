#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

using Matrix = std::vector<std::vector<int>>;

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

inline int Game_object::get_x(){
    return X_;
};
inline int Game_object::get_y(){
    return Y_;
};
inline int Game_object::get_direction(){
    return direction;
};

#endif //GAME_OBJECT_HPP