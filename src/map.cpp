#include "../headers/map.h"
#include "../headers/utils.h"
#include <iostream>

using namespace std;

Map::Map(int width, int height): width(width), height(height) {
    this->map = new char*[this->height];
    for (int i = 0; i < this->height; ++i) {
        this->map[i] = new char[this->width];
        for (int j = 0; j < this->width; ++j) {
            this->map[i][j] = '0';
        }
    }
}

void Map::render(int xStart, int yStart) const{
    for (int i = 0; i < this->height; ++i) {
        Utils::moveCursor(yStart + i, xStart);
        for (int j = 0; j < this->width; ++j) {
            cout << this->map[i][j];
        }
    }
}