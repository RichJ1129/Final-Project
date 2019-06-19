//
// Created by Richard Joseph on 2019-06-10.
//

#include "Armor.h"
#include "Player.h"

Armor::Armor() : Items()
{
    setName("Armor");
    setCost(400);
    setWeight(1);

}

Armor::~Armor()
{

}

void Armor::itemDescription()
{
    std::cout << "Ceremonial Vest that is over 10000 years old." << std::endl;
}




