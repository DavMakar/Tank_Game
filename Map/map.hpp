#include <ncurses.h>
#include <vector>

using Wall = std::vector<std::pair<int,int>>;
using Matrix = std::vector<std::vector<int>>;

class Map{
     private:
        int height;
        int width;
        Wall walls = {
            {5,35},{5,36},{6,35},{6,36},{14,45},{15,45},{19,58},{21,55},
            {21,54},{20,54},{19,57},{19,56},{19,55},{19,54},{20,55}
        };   
        
    public:
        Map(int height,int width):height(height), width(width){
            game_matrix = Matrix(height,std::vector<int>(width));
        }
        Matrix game_matrix;
        void fill_matrix();

    private:
        void add_boundaries();
        void add_walls();
};

