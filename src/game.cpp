#include "../headers/game.h"
#include "../headers/pieces.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define XSTART 2
#define YSTART 2
#define PIECE_LENGTH 16

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
            this->currentPiece = (char*)".1.."
                                        ".1.."
                                        ".1.."
                                        ".1..";
            break;
        case 1:
            this->currentPiece = (char*)".2.."
                                        ".222"
                                        "...."
                                        "....";
            break;
        case 2:
            this->currentPiece = (char*)"..3."
                                        ".333"
                                        "...."
                                        "....";
            break;
        case 3:
            this->currentPiece = (char*)".44."
                                        ".44."
                                        "...."
                                        "....";
            break;
        case 4:
            this->currentPiece = (char*)"..55"
                                        ".55."
                                        "...."
                                        "....";
            break;
        case 5:
            this->currentPiece = (char*)"..6."
                                        ".666"
                                        "...."
                                        "....";
            break;
        case 6:
            this->currentPiece = (char*)".77."
                                        "..77"
                                        "...."
                                        "....";
            break;
    };
}