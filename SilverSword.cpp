//
// Created by Richard Joseph on 2019-06-10.
//

#include "SilverSword.h"


SilverSword::SilverSword() : Items()
{
    setName("Silver Sword");
    setCost(4000);
    setWeight(1);
}

SilverSword::~SilverSword()
{

}

void SilverSword::itemDescription()
{
    std::cout << "Enhances ones attacking ability."  << std::endl;
}

