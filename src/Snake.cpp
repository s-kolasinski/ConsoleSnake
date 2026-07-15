#include "Snake.h"

Snake::Snake(){

}

void Snake::move(){

}

void Snake::grow(){

}

std::pair<int, int> Snake::getHead(){
    return body[0];
}

std::vector<std::pair<int, int>> Snake::getBody(){
    return body;
}