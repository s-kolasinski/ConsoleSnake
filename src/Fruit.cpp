#include "Fruit.h"

Fruit::Fruit(){

}

int Fruit::getX(){
    return x;
}

int Fruit::getY(){
    return y;
}

void Fruit::spawn(){
    x = 6;
    y = 7;
}