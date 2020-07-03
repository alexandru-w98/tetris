#include "../headers/game.h"
#include "../headers/hud.h"
#include <iostream>

using namespace std;

Game::Game(Hud* hud) {
    this->hud = new Hud(hud->mapWidth, hud->mapHeight);
}

void Game::render(void) const {
    this->hud->render();
}