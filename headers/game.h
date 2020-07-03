#ifndef _GAME_
#define _GAME_

#include "hud.h"

#define DEFAULT_HEIGHT 20
#define DEFAULT_WIDTH 10

class Game {
    private:
        char** map;
        Hud* hud;
    public:
        Game(Hud* hud = new Hud(DEFAULT_WIDTH, DEFAULT_HEIGHT));
        void render(void) const;
};

#endif