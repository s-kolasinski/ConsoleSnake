#include "Snake.h"

Snake::Snake(int width, int height){
    body.push_back({width/2, height/2});
    currentDirection = Direction::UP;
}

void Snake::move(){
    int newX = getHead().first;
    int newY = getHead().second;
    switch (currentDirection)
    {
    case Direction::UP:
        newY--;
        break;
    case Direction::DOWN:
        newY++;
        break;
    case Direction::RIGHT:
        newX++;
        break;
    case Direction::LEFT:
        newX--;
        break;
    default:
        break;
    }
    for(int i = body.size()-1; i > 0; i--){
        body[i] = body[i-1];
    }
    body[0] = {newX, newY};
}

void Snake::grow(){
    body.push_back(body.back());
}

std::pair<int, int> Snake::getHead(){
    return body[0];
}

std::vector<std::pair<int, int>> Snake::getBody(){
    return body;
}

Direction Snake::getDirection(){
    return currentDirection;
}

void Snake::setDirection(Direction newDir){
    currentDirection = newDir;
}