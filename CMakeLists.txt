cmake_minimum_required(VERSION 3.16.3)
project(Tank_Game)

file(GLOB SOURCES "src/libs/*.cpp" "src/Map/*.cpp" "src/Game_object/*.cpp" "src/Enemy/*.cpp" "src/Game/*.cpp" "src/Player/*.cpp" "src/Map/*.cpp" "src/Menu/*.cpp" "src/Controller/*.cpp" "src/View/*.cpp")

add_compile_options()

add_executable(Tank_Game main.cpp ${SOURCES})

target_link_libraries(Tank_Game -lncurses)

set_property(TARGET Tank_Game PROPERTY CXX_STANDARD 14)
