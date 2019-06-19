//
// Created by Richard Joseph on 2019-06-02.
//

#include "Hero.h"

Hero::Hero() : Player()
{
    this->name = "Hero";
    this->setAttack(1, 6);
    this->setAttackArray(1);
    this->setDefense(1, 6);
    this->setDefenseArray(1);
    this->setStrPoints(25);
    this->setArmor(0);
    this->setMoney(0);
    this->setDays(365);
}

int Hero::getPlayerType()
{
    return 1;
}

void Hero::description()
{
    
}



