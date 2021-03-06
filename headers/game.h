#ifndef _GAME_
#define _GAME_

#include "hud.h"
#include "map.h"

#define DEFAULT_HEIGHT 20
#define DEFAULT_WIDTH 10

class Game {
    private:
        Map* map;
        Hud* hud;
        char* currentPiece;
        int currentPieceRow;
        char currentPieceColor;
        int currentPieceHeight;
    public:
        Game(Hud* hud = new Hud(DEFAULT_WIDTH, DEFAULT_HEIGHT),
             Map* map = new Map(DEFAULT_WIDTH, DEFAULT_HEIGHT));
        void init(void) const;
        void render(void) const;
        void generatePiece(void);
        void getUserInput(void);
        bool isValidMovement(char direction) const;
        void movePiece(char direction);
        void gameLoop(void);
};

#endif