//
// Created by Richard Joseph on 2019-06-01.
//

#include "Dice.h"


Dice::Dice(int userDice)
{
    numSides = userDice;
}

void Dice::setNumSides(int userInput)
{
    numSides = userInput;
}

int Dice::getNumSides()
{
    return numSides;
}

//Roll dice function using rand function
int Dice::rollDie() const
{
    int rolledNum = 0;


    rolledNum = (rand() % numSides) + 1;

    return rolledNum;
}
