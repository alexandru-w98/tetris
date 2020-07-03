#include "../headers/utils.h"
#include <iostream>

using namespace std;

void Utils::clearScreen(void) {
    cout << "\033[2J" << flush;
}

void Utils::moveCursor(int row, int column) {
    cout << "\033[" << row << ';' << column << 'H' << flush;
}