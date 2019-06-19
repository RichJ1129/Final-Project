//
// Created by Richard Joseph on 2019-06-04.
//

#ifndef FINALPROJECT_BEDROOM_H
#define FINALPROJECT_BEDROOM_H

#include "Space.h"

class Bedroom : public Space
{

public:
    Bedroom(Player *);
    ~Bedroom();
    void enterRoom();
    void performAction(int);
};


#endif //FINALPROJECT_BEDROOM_H
