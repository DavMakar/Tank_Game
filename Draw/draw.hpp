// #include <vector>
// #include "../Game/game.hpp"

// class Draw{
//     public:
//         Draw(const Tank_Game &);
//         //void draw_map(Tank_Game &);

//     private:
//         Tank_Game game_model_;
//         const char wall_pattern[3] = "[]";    
// };

// Draw::Draw(const Tank_Game & game_model)
//     :game_model_{game_model}
// {};

// void Draw::draw_tank(){
//     Tank t1 = game_model_->tank;
//     const int Y_ = t1.get_y();
//     const int X_ = t1.get_x();
//     const auto direction = t1.get_direction();
//     if(direction<2){
//         for(int i= -1 ;i<1 ;++i){ //TODO need change
//             mvwprintw(game_window_,Y_ + i,X_,tank_pattern_ud[direction][i+1]);
//         }
//     }else{
//         for(int i= -1 ;i<2 ;++i){ 
//             mvwprintw(game_window_,Y_ + i,X_,tank_pattern_lr[direction-2][i+1]);
//         }
//     }
// }

// void Draw::erase_tank(){    
// }
