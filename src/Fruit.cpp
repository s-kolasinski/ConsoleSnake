#include "Fruit.h"
#include <cstdlib>

Fruit::Fruit(int width, int height){
    spawn(width, height);
}

int Fruit::getX(){
    return x;
}

int Fruit::getY(){
    return y;
}

void Fruit::spawn(int width, int height){
    x = rand() % (width - 2) + 1;
    y = rand() % (height - 2) + 1;
}