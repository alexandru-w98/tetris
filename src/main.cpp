#include "../headers/utils.h"
#include "../headers/game.h"
#include "../headers/hud.h"
#include <iostream>

using namespace std;

int main() {
    Utils::clearScreen();
    
    Game* tetris = new Game();
    tetris->init();
    tetris->generatePiece();
    tetris->render();
    //tetris->getUserInput();
    tetris->gameLoop();

    return 0;
}