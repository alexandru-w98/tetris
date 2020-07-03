#include "../headers/hud.h"
#include "../headers/utils.h"
#include <iostream>

using namespace std;

#define BORDER_OFFSET 1

Hud::Hud(void) { }

Hud::Hud(int width, int height): mapWidth(width), mapHeight(height) { }

void Hud::render(void) const {
    Utils::moveCursor(1, 1);
    cout << '+';
    Utils::moveCursor(this->mapHeight + BORDER_OFFSET * 2, 1);
    cout << '+';

    for (int i = 2; i < this->mapWidth + BORDER_OFFSET * 2; ++i) {
        Utils::moveCursor(1, i);
        cout << '-';
        Utils::moveCursor(this->mapHeight + BORDER_OFFSET * 2, i);
        cout << '-';
    }

    for (int i = 2; i < this->mapHeight + BORDER_OFFSET * 2; ++i) {
        Utils::moveCursor(i, 1);
        cout << '|';
        Utils::moveCursor(i, this->mapWidth + BORDER_OFFSET * 2);
        cout << '|';
    }

    Utils::moveCursor(1, this->mapWidth + BORDER_OFFSET * 2);
    cout << '+';
    Utils::moveCursor(this->mapHeight + BORDER_OFFSET * 2, this->mapWidth + BORDER_OFFSET * 2);
    cout << '+';
}

int Hud::getMapWidth(void) const { 
    return this->mapWidth;
}

int Hud::getMapHeight(void) const {
    return this->mapHeight;
}