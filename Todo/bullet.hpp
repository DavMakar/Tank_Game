#include <ncurses.h>

class Bullet{
    public:
        Bullet(int x,int y,int dir,WINDOW* b);
        //void move();
        bool check_colison();
    private:
        int X_;
        int Y_;
        int direction;
        WINDOW* board;
        const char bullet_sym = ACS_BULLET; //ACS_BULLET;
};

Bullet::Bullet(int x,int y,int dir,WINDOW* b){
    X_ = x;
    Y_ = y;
    direction = dir;
    board = b;
}

// 0 up 
// 1 down
// 2 left
// 3 right

// bool check_colison(){
//     //if direction //up
//         //while (board[Y-1][X] != 1)
//         //  erase_bullet
//         //  --Y;
//         //  display_bullet
//     return true;
// }

//void Bullet::move(){
//    mvwaddch(board,Y_,X_,bullet_sym);
//}