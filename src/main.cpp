#include "../headers/utils.h"
#include "../headers/game.h"
#include "../headers/hud.h"
#include <iostream>

using namespace std;

#define HEIGHT 20
#define WIDTH 10

int main() {
    Utils::clearScreen();
    
    Game* tetris = new Game();
    tetris->render();

    Utils::moveCursor(HEIGHT + 20, 1);
    return 0;
}