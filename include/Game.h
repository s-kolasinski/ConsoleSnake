#pragma once
#include "Snake.h"
#include "Fruit.h"

class Game{
    private:
    
        int width;
        int height;
        int score;
        bool gameOver;
        Snake playerSnake;
        Fruit apple;

    public:
        Game();
        void run();

    private:
        void draw();
        void input();
        void logic();
};