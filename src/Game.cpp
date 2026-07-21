#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <fstream>
#include <string>

Game::Game():width(20),height(20), playerSnake(width, height), apple(width, height){

    currentDifficulty = Difficulty::EASY;
    score = 0;
    gameOver = false;
}

bool Game::run(){
    
    system("cls");
    
    auto lastTime = std::chrono::steady_clock::now();
    
    
    while(!gameOver){
        
        std::cout << "\x1B[H";
        input();

        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();

        if(elapsedTime >= (int64_t)currentDifficulty){
            draw();
            logic();
            lastTime = currentTime;
        }

    
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "========================================\n";
    std::cout << "               GAME OVER!               \n";
    std::cout << "========================================\n";
    std::cout << "               SCORE: " << score << "               \n";
    if(isRecord())
    std::cout << "       !!!!!!NEW RECORD!!!!!!\n"  ;
    std::cout << "          PRESS R TO TRY AGAIN\n";
    std::cout << "            PRESS Q TO QUIT\n";
    
    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    while(true){
        char key = _getch();
        if(key == 'q' || key == 'Q'){
            return false;
            break;
        }
        else if(key == 'r' || key == 'R'){
            return true;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void Game::draw(){
    
    
    std::string frame = "";
    std::vector<std::pair<int, int>> body = playerSnake.getBody();
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            bool isBody = false;
            if(i == 0 || i == height-1 || j == 0 || j == width-1)
            frame += "#";
            else if(j == playerSnake.getHead().first && i == playerSnake.getHead().second)
            frame += "O";
            else if(j == apple.getX() && i == apple.getY())
            frame += "F";
            else{
            for(int k = 1; k < body.size(); k++){
                if(body[k].first == j && body[k].second == i){
                    frame += "o";
                    isBody = true;
                    break;
                }
            }
            if(!isBody) 
            frame += " ";
            }
        }
        frame += '\n';
    }
    std::cout << frame;
    std::cout << "\nSCORE: " << score;
}

void Game::input(){
    while(_kbhit()){
        char currentInput = _getch();
        switch (currentInput)
        {
        case 'w':
        case 'W':
            if(playerSnake.getDirection() != Direction::DOWN)
            playerSnake.setDirection(Direction::UP);
            break;
        case 's':
        case 'S':
            if(playerSnake.getDirection() != Direction::UP)
            playerSnake.setDirection(Direction::DOWN);
            break;
        case 'd':
        case 'D':
            if(playerSnake.getDirection() != Direction::LEFT)
            playerSnake.setDirection(Direction::RIGHT);
            break;
        case 'a':
        case 'A':
            if(playerSnake.getDirection() != Direction::RIGHT)
            playerSnake.setDirection(Direction::LEFT);
            break;
        case 'q':
        case 'Q':
            gameOver = true;
            break;
        
    
        }
    }
}

void Game::logic(){
    playerSnake.move();
    if(playerSnake.getHead().first == 0 || 
    playerSnake.getHead().first == width-1 ||
    playerSnake.getHead().second == 0 ||
    playerSnake.getHead().second == height-1)
    gameOver = true;
        for(int i = 1; i < playerSnake.getBody().size(); i++){
            if(playerSnake.getHead() == playerSnake.getBody()[i])
            gameOver = true;
        }
    if(playerSnake.getHead().first == apple.getX() && playerSnake.getHead().second ==  apple.getY()){
        playerSnake.grow();
        apple.spawn(width, height);
        score++;
    }
    if(score == 5) currentDifficulty = Difficulty::MEDIUM;
    if(score == 10) currentDifficulty = Difficulty::HARD;

}

bool Game::isRecord(){
    int highScore = 0;

    std::ifstream readFile("best_score.txt");
    if(readFile.is_open()){
        readFile >> highScore;
        readFile.close();
    }
    bool isNewRecord = false;

    if(score > highScore){
        isNewRecord = true;

        std::ofstream saveFile("best_score.txt");
        if(saveFile.is_open()){
            saveFile << score;
            saveFile.close();
        }
    }
    return isNewRecord;
}