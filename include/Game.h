#pragma once
#include "Snake.h"
#include "Fruit.h"

class Game{
    private:
        Snake playerSnake;
        Fruit apple;
    
        int width;
        int height;
        int score;
        bool gameOver;

    public:
        Game();
        void run();

    private:
        void draw();
        void input();
        void logic();
};