#include <ncurses.h>
#include <vector>

using Wall = std::vector<std::pair<int,int>>;
using Matrix = std::vector<std::vector<int>>;

class Map{
    public:
        Map(int height,int width);
        void fill_matrix();
        Matrix get_matrix();

    private:
        void add_boundaries();
        void add_walls();

    private:
        int height;
        int width;
        Matrix game_map{25,std::vector<int>(100)};
        Wall walls = {
            {5,35},{14,45},{19,58},{22,40}
        };
};

