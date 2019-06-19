//
// Created by Richard Joseph on 2019-06-01.
//

#ifndef FINALPROJECT_DICE_H
#define FINALPROJECT_DICE_H

#include <iostream>
#include <ctime>
#include <cstdlib>

class Dice
{
protected:
    int numSides;

public:
    Dice(int);
    void setNumSides(int);
    int getNumSides();

    int rollDie() const;
};


#endif //FINALPROJECT_DICE_H
