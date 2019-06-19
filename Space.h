//
// Created by Richard Joseph on 2019-06-01.
//

#ifndef FINALPROJECT_SPACE_H
#define FINALPROJECT_SPACE_H

#include "Player.h"
#include "Menu.h"

class Space
{
protected:
    Space *top;
    Space *right;
    Space *bottom;
    Space *left;
    std::string name;
    Player *player;
    Menu *spaceItems;
    std::string exit;

public:
    Space();
    Space(std::string, Player *);
    virtual ~Space();
    virtual void enterRoom() = 0;
    virtual void performAction(int) = 0;
    void setTop(Space *);
    void setRight(Space *);
    void setBottom(Space *);
    void setLeft(Space *);
    void setName(std::string);
    Space *getTop();
    Space *getRight();
    Space *getBottom();
    Space *getLeft();
    std::string getName();
    Player *getPlayer();
    void setPlayer(Player *);
};


#endif //FINALPROJECT_SPACE_H
