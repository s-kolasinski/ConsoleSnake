#pragma once
#include <vector>
#include <utility>

enum class Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake{
    private:
        std::vector<std::pair<int, int>> body;
        Direction currentDirection;
    public:
        Snake();

        void move();

        void grow();

        std::pair<int, int> getHead();

        std::vector<std::pair<int, int>> getBody();
};