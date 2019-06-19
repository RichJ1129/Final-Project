//
// Created by Richard Joseph on 2019-06-04.
//

#include "Items.h"

Items::Items()
{
}

void Items::setName(std::string userInput)
{
    name = userInput;
}

std::string Items::getName()
{
    return name;
}

void Items::setCost(int userInput)
{
    cost = userInput;
}

int Items::getCost()
{
    return cost;
}




void Items::itemDescription()
{
    
}

int Items::getWeight()
{
    return weight;
}

void Items::setWeight(int userIn)
{
    weight = userIn;
}

Items::~Items()
{
    
}
