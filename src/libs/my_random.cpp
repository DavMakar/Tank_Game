#include "my_random.hpp"

int roll_die(){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,8);
    
    return dist(mt);
}

std::pair<int,int> random_wall(){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist_y(1,24);
    std::uniform_int_distribution<int> dist_x(20,80);
    return std::make_pair(dist_y(mt),dist_x(mt));
}

int random_direction(){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0,3);
    return dist(mt);
}