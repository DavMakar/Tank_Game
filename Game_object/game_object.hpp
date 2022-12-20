#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

using Matrix = std::vector<std::vector<int>>;

enum Directions {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
};

class game_object
{
protected:
    int X_;
    int Y_;
    int direction{};

public:
    game_object(int,int);
    int get_y();
    int get_x();
    int get_direction();
};

inline game_object::game_object(int Y,int X)
{
    Y_ = Y;
    X_ = X;
}

inline int game_object::get_x(){
    return X_;
};
inline int game_object::get_y(){
    return Y_;
};
inline int game_object::get_direction(){
    return direction;
};

#endif //GAME_OBJECT_HPP