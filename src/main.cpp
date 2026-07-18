#include <iostream>
#include "Game.h"
#include <ctime>
#include <conio.h>

int main(){
    srand(time(NULL));

    Game myGame;

    myGame.run();

    return 0;
}