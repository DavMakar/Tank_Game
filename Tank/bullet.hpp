#include <vector>
#include "../Game_object/game_object.hpp"

using Matrix = std::vector<std::vector<int>>;

class Bullet
        :public game_object{
    private:
        const unsigned int speed = 32768;
    public:
        Bullet(WINDOW* win,int x,int y,int dir);
        void move(Matrix &);
        void display();
        bool detect_collision(Matrix &);
        void erase();
};

