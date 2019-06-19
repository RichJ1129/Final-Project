//
// Created by Richard Joseph on 2019-06-01.
//

#ifndef FINALPROJECT_HOME_H
#define FINALPROJECT_HOME_H

#include "Space.h"

class Home : public Space
{

public:
    Home(Player *player);
    ~Home();
    void enterRoom();
    void performAction(int);
};


#endif //FINALPROJECT_HOME_H
