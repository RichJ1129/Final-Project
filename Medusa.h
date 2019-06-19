//
// Created by Richard Joseph on 2019-06-05.
//

#ifndef FINALPROJECT_MEDUSA_H
#define FINALPROJECT_MEDUSA_H

#include "Player.h"

class Medusa : public Player
{
public:
    Medusa();
    Medusa(std::string);
    int attackOpp();
    void specialAbility(int &);
    void description();
};


#endif //FINALPROJECT_MEDUSA_H
