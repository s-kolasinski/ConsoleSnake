#pragma once
#include "Snake.h"
#include "Fruit.h"

enum class Difficulty{
    EASY = 500,
    MEDIUM = 300,
    HARD = 100,
};


class Game{
    private:
    
        int width;
        int height;
        int score;
        bool gameOver;
        Difficulty currentDifficulty;
        Snake playerSnake;
        Fruit apple;


    public:
        Game();
        bool run();

    private:
        void draw();
        void input();
        void logic();
};