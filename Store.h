//
// Created by Richard Joseph on 2019-06-04.
//

#ifndef FINALPROJECT_STORE_H
#define FINALPROJECT_STORE_H

#include "Space.h"
#include "Armor.h"
#include "Mirror.h"
#include "Stake.h"
#include "SilverSword.h"
#include "EnergyDrink.h"

class Store : public Space
{
public:
    Store(Player *);
    ~Store();
    void enterRoom();
    void performAction(int);
};


#endif //FINALPROJECT_STORE_H
