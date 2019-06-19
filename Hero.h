//
// Created by Richard Joseph on 2019-06-02.
//

#ifndef FINALPROJECT_HERO_H
#define FINALPROJECT_HERO_H

#include "Player.h"

class Hero : public Player
{
private:
    int days;

public:
    Hero();
    virtual int getPlayerType();
    void seeStats();
    void description();
};


#endif //FINALPROJECT_HERO_H
