#include "../headers/utils.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Utils::clearScreen(void) {
    cout << "\033[2J" << flush;
}

void Utils::moveCursor(int row, int column) {
    cout << "\033[" << row << ';' << column << 'H' << flush;
}

void Utils::waitDelay(unsigned long millis) {
    this_thread::sleep_for(chrono::milliseconds(millis));
}