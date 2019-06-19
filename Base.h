//
// Created by Richard Joseph on 2019-06-04.
//

#ifndef FINALPROJECT_BASE_H
#define FINALPROJECT_BASE_H

#include "Space.h"
#include "Hero.h"
#include "Gargoyle.h"
#include "Vampire.h"
#include "Medusa.h"
#include "BlueMen.h"

class Base : public Space
{
public:
    Base(Player *);
    ~Base();
    void enterRoom();
    void performAction(int);
    Player *fightOpponent(Player *, Player *);
};


#endif //FINALPROJECT_BASE_H
