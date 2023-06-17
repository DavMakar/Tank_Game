#include "view.hpp"

void make_header();

View::View(Game & game_model)
                           :game_model_{game_model},
                            menu_view_{game_model.menu_model_}
{
    initscr();
    use_default_colors();
    noecho();
    curs_set(0);
    game_win_ = newwin(game_model_.Map_params::height,game_model_.Map_params::width,game_model_.Map_params::pos_y,game_model.Map_params::pos_x);
    refresh();
    make_header();
};

void View::draw_game_scene(){
    clear();
    refresh();
    nodelay(game_win_,true);
    make_header();
    Matrix game_matrix = game_model_.game_map.get_matrix();
    box(game_win_, 0, 0);
    wrefresh(game_win_);
    render();
};

void View::display_healths(){
    mvprintw(8 ,90 ,"Enemy Health : %d",game_model_.game_map.enemy_tank.health);
    mvprintw(8 ,10 ,"Player Health : %d",game_model_.game_map.player_tank.health);
    refresh();
}

void View::render(){
    display_healths();
    Matrix game_matrix = game_model_.game_map.get_matrix();
    for(auto i = 1 ; i < game_matrix.size()-1 ; ++i){
        for(auto j = 1 ; j< game_matrix[0].size()-1 ; ++j){
            switch (game_matrix[i][j])
            {
            case Map::Matrix_cell_type::wall:
                draw_wall(i,j);
                break;
            case Map::Matrix_cell_type::player:
                draw_player(i,j);
                break;
            case Map::Matrix_cell_type::enemy:
                draw_enemy(i,j);
                break;
            case Map::Matrix_cell_type::bullet:
                draw_bullet(i,j);
                break;
            case Map::Matrix_cell_type::empty:
                draw_empty(i,j);
            default:
                break;
            }
        }
    }
}

void View::draw_player(int i ,int j){
    auto player = game_model_.game_map.player_tank;
    for(int k = -2 ; k <= 0 ;++k){ 
        mvwprintw(game_win_ , i+k , j-2 ,player.player_pattern[player.get_direction()][k+2]);
    }
}

void View::draw_enemy(int i ,int j){
    auto enemy = game_model_.game_map.enemy_tank;
        for(int k = -2 ; k <= 0 ;++k){ 
            mvwprintw(game_win_ , i+k , j-2 , enemy.enemy_pattern[enemy.get_direction()][k+2]);
        }
}

void View::draw_wall(int i ,int j){
    mvwaddch(game_win_,i,j,ACS_CKBOARD);
}
void View::draw_empty(int i ,int j){
    mvwaddch(game_win_,i,j,' ');
}
void View::draw_bullet(int i ,int j){
    mvwaddch(game_win_,i,j,ACS_BULLET);
}

void make_header(){
    mvprintw(0,30," ___________              __       ________");
    mvprintw(1,30,"\\__    ___/____    ____ |  | __  /  _____/_____    _____   ____");
    mvprintw(2,30,"  |    |  \\__  \\  /    \\|  |/ / /   \\  ___\\__  \\  /     \\_/ __ \\ ");
    mvprintw(3,30,"  |    |   / __ \\|   |  \\    <  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ ");
    mvprintw(4,30,"  |____|  (____  /___|  /__|_ \\  \\______  (____  /__|_|  /\\___  >");
    mvprintw(5,30,"               \\/     \\/     \\/         \\/     \\/      \\/     \\/ ");
}

void View::end_screen(){
    if(game_model_.is_lose()){
        game_over_screen();
    }else if(game_model_.is_win()){
        game_win_screen();
    } 
        nodelay(game_win_,false);
        wgetch(game_win_);
        wgetch(game_win_);
        wclear(game_win_);
        wrefresh(game_win_);
}

void View::game_over_screen(){
    werase(game_win_);

    mvwprintw(game_win_,10,15,"   _____                                 ____                            ");                       
    mvwprintw(game_win_,11,15,"  / ____|                               / __ \\                           ");                       
    mvwprintw(game_win_,12,15," | |  __    __ _   _ __ ___     ___    | |  | | __   __   ___   _ __  ");
    mvwprintw(game_win_,13,15," | | |_ |  / _` | | '_ ` _ \\   / _ \\   | |  | | \\ \\ / /  / _ \\ | '__| ");
    mvwprintw(game_win_,14,15," | |__| | | (_| | | | | | | | |  __/   | |__| |  \\ V /  |  __/ | |    ");
    mvwprintw(game_win_,15,15,"  \\_____|  \\__,_| |_| |_| |_|  \\___|    \\____/    \\_/    \\___| |_|       ");
                                                                    
    mvwprintw(game_win_,18,35,"PRESS ANY KEY TO RETURN MENU ");
    wrefresh(game_win_);
}

void View::game_win_screen(){
    werase(game_win_);

    mvwprintw(game_win_,10,15," __     __   ____    _    _    __          __  _____   _   _  ");
    mvwprintw(game_win_,11,15," \\ \\   / /  / __ \\  | |  | |   \\ \\        / / |_   _| | \\ | | ");
    mvwprintw(game_win_,12,15,"  \\ \\_/ /  | |  | | | |  | |    \\ \\  /\\  / /    | |   |  \\| | ");
    mvwprintw(game_win_,13,15,"   \\   /   | |  | | | |  | |     \\ \\/  \\/ /     | |   | . ` | ");
    mvwprintw(game_win_,14,15,"    | |    | |__| | | |__| |      \\  /\\  /     _| |_  | |\\  | ");
    mvwprintw(game_win_,15,15,"    |_|     \\____/   \\____/        \\/  \\/     |_____| |_| \\_| ");
                                                             
    mvwprintw(game_win_,18,35,"PRESS ANY KEY TO RETURN MENU ");
    wrefresh(game_win_);
}