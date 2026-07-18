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
        Snake(int width, int height);

        void move();

        void grow();

        std::pair<int, int> getHead();

        std::vector<std::pair<int, int>> getBody();

        Direction getDirection();

        void setDirection(Direction newDir);
};