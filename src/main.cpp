#include <iostream>
#include "Game.h"
#include <ctime>
#include <conio.h>

int main(){
    srand(time(NULL));

    bool playAgain = true;

    while(playAgain){
    Game myGame;
    playAgain = myGame.run();
    }

    return 0;
}