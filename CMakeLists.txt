cmake_minimum_required(VERSION 3.10)
project(ConsoleSnake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(SnakeGame
                src/main.cpp
                src/Fruit.cpp
                src/Game.cpp
                src/Snake.cpp)