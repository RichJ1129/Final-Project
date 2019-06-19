//
// Created by Richard Joseph on 2019-06-10.
//

#include "EnergyDrink.h"


EnergyDrink::EnergyDrink() : Items()
{
    setName("Energy Drink");
    setCost(100);
    setWeight(1);
}

EnergyDrink::~EnergyDrink()
{

}

void EnergyDrink::itemDescription()
{
    std::cout << "Health is restored by 25 points" << std::endl;
}


