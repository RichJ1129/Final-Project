//
// Created by Richard Joseph on 2019-06-05.
//

#ifndef FINALPROJECT_VAMPIRE_H
#define FINALPROJECT_VAMPIRE_H

#include "Player.h"

class Vampire : public Player
{
public:
    Vampire();
    Vampire(std::string);
    int defense(int);
    bool specialAbility();
    void description();
};


#endif //FINALPROJECT_VAMPIRE_H
