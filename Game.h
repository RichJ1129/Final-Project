//
// Created by Richard Joseph on 2019-06-05.
//

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H

#include <iomanip>
#include <algorithm>
#include "Dojo.h"
#include "Bedroom.h"
#include "Base.h"
#include "Home.h"
#include "Store.h"
#include "Hero.h"

class Game
{
private:
    Space *base;
    Space *dojo;
    Space *bedroom;
    Space *home;
    Space *store;
    Space *currLocation;
    Hero *hero;
    Menu *gameMenu;
    Menu *spaceMenu;

public:
    Game();
    ~Game();
    void createMap();
    void destroyMap();
    void startGame();
    void endGame();
    void printMap();
    void takeTurn();
    void seeStats();
};


#endif //FINALPROJECT_GAME_H
