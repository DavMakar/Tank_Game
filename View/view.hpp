#include <vector>
#include "../Game/game.hpp"

class View{
    private:
        Tank_Game & game_model_;
            
    public:
        View(Tank_Game &);
        void draw_map();
        void update();

    private:
        void draw_tank();
};