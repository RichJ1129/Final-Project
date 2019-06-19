//
// Created by Richard Joseph on 2019-06-10.
//

#include "Stake.h"

Stake::Stake() : Items()
{
    setName("Stake");
    setCost(10000);
    setWeight(1);
}

Stake::~Stake()
{

}

void Stake::itemDescription()
{
    std::cout << "Only way the Vampire can be killed permanently."  << std::endl;
}


