//
// Created by Richard Joseph on 2019-06-05.
//

#include "Gargoyle.h"

Gargoyle::Gargoyle()
{
    this->name = "Gargoyle";
    this->setAttack(2, 6);
    this->attackArray = 2;
    this->setDefense(2, 6);
    this->defenseArray = 2;
    this->setStrPoints(12);
    this->setArmor(0);
    this->setMoney(10);
}

Gargoyle::Gargoyle(std::string user)
{
    this->name = user;
    this->setAttack(2, 6);
    this->attackArray = 2;
    this->setDefense(2, 6);
    this->defenseArray = 2;
    this->setStrPoints(12);
    this->setArmor(0);
}

void Gargoyle::description()
{
    std::cout << "A nocturnal creature, not much is known, should not be taken lightly but who knows." << std::endl;
}
