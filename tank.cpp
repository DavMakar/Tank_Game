#include "tank.hpp"

Tank::Tank(WINDOW * w ,int X,int Y){
    X_ = X;
    Y_ = Y;
    win = w;    
}

bool Tank::can_move(){
    if(direction == 0){
        return Y_ > min_Y;
    }
    if(direction ==1){
        return Y_ < max_Y;
    }
    if(direction == 2){
        return X_> min_X;
    }
    if(direction == 3){
        return X_< max_X;
    }
    
    return true;
}

void Tank::display_Tank(){
    if(direction<2){
        for(int i= -1 ;i<1 ;++i){ //need change
            mvwprintw(win,Y_ + i,X_,tank_pattern_ud[direction][i+1]);
        }
    }else{
        for(int i= -1 ;i<2 ;++i){ 
            mvwprintw(win,Y_ + i,X_,tank_pattern_lr[direction-2][i+1]);
        }
    }
};

void Tank::erase_Tank(){
    // if(direction<2){
    //     for(int i= -1 ;i<1 ;++i){ 
    //         mvwprintw(win,Y_ + i,X_,"     ");
    //     }
    // }
    for(int i= -1 ;i<2 ;++i){ 
        mvwprintw(win,Y_ + i,X_,"     ");
    }
};


void Tank::go_down(){
    if(can_move()){
        erase_Tank();
        Y_+=1;
        display_Tank();
    }
    
};

void Tank::go_left(){
    if(can_move()){
        erase_Tank();
        X_-=1;
        display_Tank();
    }
}
void Tank::go_right(){
    if(can_move()){
        erase_Tank();
        X_+=1;
        display_Tank();
    }
}
void Tank::go_up(){
    if(can_move()){
        erase_Tank();
        Y_-=1;
        display_Tank(); 
    }
};

// TO DO
//void Tank::shot(){
// 
//}
//

void Tank::change_direction(int d){
    direction = d;
};
 