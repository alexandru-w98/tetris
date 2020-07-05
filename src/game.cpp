#include "../headers/game.h"
#include "../headers/pieces.h"
#include "../headers/utils.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

#define XSTART 2
#define YSTART 2
#define PIECE_LENGTH 16
#define LEFT_KEY 30 // a
#define RIGHT_KEY 32 // d
#define DOWN_KEY 31 // s

struct KeyboardInput {
    long time1, time2;
    unsigned short type;
    unsigned short code;
    unsigned int value;
};

Game::Game(Hud* hud, Map* map): currentPieceRow(0) {
    this->hud = new Hud(hud->mapWidth, hud->mapHeight);
    this->map = new Map(map->width, map->height);
    this->currentPiece = new char[PIECE_LENGTH];
}

void Game::init(void) const { 
    this->hud->render();
    this->map->render(XSTART, YSTART);
}

void Game::render(void) const {
    int piecePositionOffset = (DEFAULT_WIDTH - 2) / 2 - 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (this->currentPiece[i * 4 + j] != '.') {
                this->map->map[currentPieceRow + i][piecePositionOffset + j] = this->currentPiece[i * 4 + j];
            }
        }
    }
    this->map->render(XSTART, YSTART);
}

void Game::generatePiece(void) {
    srand(time(NULL));

    switch(rand() %  Pieces::Length) {
        case 0:
            this->currentPiece = (char*)".x.."
                                        ".x.."
                                        ".x.."
                                        ".x..";
            this->currentPieceColor = 'C';
            this->currentPieceHeight = 4;
            break;
        case 1:
            this->currentPiece = (char*)".x.."
                                        ".xxx"
                                        "...."
                                        "....";
            this->currentPieceColor = 'B';
            this->currentPieceHeight = 2;
            break;
        case 2:
            this->currentPiece = (char*)"...x"
                                        ".xxx"
                                        "...."
                                        "....";
            this->currentPieceColor = 'O';
            this->currentPieceHeight = 2;
            break;
        case 3:
            this->currentPiece = (char*)".xx."
                                        ".xx."
                                        "...."
                                        "....";
            this->currentPieceColor = 'Y';
            this->currentPieceHeight = 2;
            break;
        case 4:
            this->currentPiece = (char*)"..xx"
                                        ".xx."
                                        "...."
                                        "....";
            this->currentPieceColor = 'G';
            this->currentPieceHeight = 2;
            break;
        case 5:
            this->currentPiece = (char*)"..x."
                                        ".xxx"
                                        "...."
                                        "....";
            this->currentPieceColor = 'P';
            this->currentPieceHeight = 2;
            break;
        case 6:
            this->currentPiece = (char*)".xx."
                                        "..xx"
                                        "...."
                                        "....";
            this->currentPieceColor = 'R';
            this->currentPieceHeight = 2;
            break;
    };
}

void Game::getUserInput(void) {
    ifstream keyboardFile((char*)"/dev/input/event0", ios::in | ios::binary);
    KeyboardInput kbInput;

    if (!keyboardFile) {
        cerr << "Cannot read keyboard input" << endl;
        return;
    }

    while(1) {
        Utils::moveCursor(DEFAULT_HEIGHT + 20, 1);
        keyboardFile.read((char*)&kbInput, sizeof(KeyboardInput));

        if (kbInput.type == 1 && kbInput.value == 1 && kbInput.code != 0) {
            switch(kbInput.code) {
                case LEFT_KEY:
                    if (this->isValidMovement('L')) {
                        this->movePiece('L');
                        this->map->render(XSTART, YSTART);
                        this->hud->render();
                        Utils::moveCursor(DEFAULT_HEIGHT + 20, 1);
                    }
                    break;
                case RIGHT_KEY:
                    if (this->isValidMovement('R')) {
                        this->movePiece('R');
                        this->map->render(XSTART, YSTART);
                        this->hud->render();
                        Utils::moveCursor(DEFAULT_HEIGHT + 20, 1);
                    }
                    break;
                case DOWN_KEY:
                    if (this->isValidMovement('D')) {
                        this->movePiece('D');
                        this->map->render(XSTART, YSTART);
                        this->hud->render();
                        this->currentPieceRow += 1;

                        Utils::moveCursor(DEFAULT_HEIGHT + 20, 1);
                    }
                    break;
            }
        }
    }

    keyboardFile.close();
}

bool Game::isValidMovement(char direction) const {
    switch(direction) {
        case 'L': 
            for (int i = this->currentPieceRow; i < this->currentPieceRow + this->currentPieceHeight; ++i) {
                for (int j = 0; j < DEFAULT_WIDTH; ++j) {
                    if (this->map->map[i][j] == 'x') {
                        if (j - 1 >= 0 && this->map->map[i][j - 1] == ' ') {
                            break;
                        } else {
                            return false;
                        }
                    }
                }
            }
            return true;
        case 'R':
            for (int i = this->currentPieceRow; i < this->currentPieceRow + this->currentPieceHeight; ++i) {
                for (int j = DEFAULT_WIDTH - 1; j >= 0; --j) {
                    if (this->map->map[i][j] == 'x') {
                        if (j + 1 < DEFAULT_WIDTH && this->map->map[i][j + 1] == ' ') {
                            break;
                        } else {
                            return false;
                        }
                    }
                }
            }
            return true;
        case 'D':
            for (int i = 0; i < DEFAULT_WIDTH; ++i) {
                for (int j = this->currentPieceRow + this->currentPieceHeight - 1; j >= this->currentPieceRow; --j) {
                    if (this->map->map[j][i] == 'x') {
                        if (j + 1 < DEFAULT_HEIGHT && this->map->map[j + 1][i] == ' ') {
                            break;
                        } else {
                            return false;
                        }
                    }
                }
            }
            return true;
    }
    return false;
}

void Game::movePiece(char direction) {
    switch(direction) {
        case 'L':
            for (int i = this->currentPieceRow; i < this->currentPieceRow + this->currentPieceHeight; ++i) {
                for (int j = 0; j < DEFAULT_WIDTH; ++j) {
                    if (this->map->map[i][j] == 'x') {
                        this->map->map[i][j - 1] = 'x';
                        this->map->map[i][j] = ' ';
                    }
                }
            }
            break;
        case 'R':
            for (int i = this->currentPieceRow; i < this->currentPieceRow + this->currentPieceHeight; ++i) {
                for (int j = DEFAULT_WIDTH - 1; j >= 0; --j) {
                    if (this->map->map[i][j] == 'x') {
                        this->map->map[i][j + 1] = 'x';
                        this->map->map[i][j] = ' ';
                    }
                }
            }
            break;
        case 'D':
            for (int i = this->currentPieceRow + this->currentPieceHeight - 1; i >= this->currentPieceRow; --i) {
                for (int j = DEFAULT_WIDTH - 1; j >= 0; --j) {
                    if (this->map->map[i][j] == 'x') {
                        this->map->map[i + 1][j] = 'x';
                        this->map->map[i][j] = ' ';
                    }
                }
            }
            break;
    }
}