//
// Created by Richard Joseph on 2019-06-04.
//

#ifndef FINALPROJECT_DOJO_H
#define FINALPROJECT_DOJO_H

#include "Space.h"

class Dojo : public Space
{

public:
    Dojo(Player *);
    ~Dojo();
    void enterRoom();
    void performAction(int);
};


#endif //FINALPROJECT_DOJO_H
