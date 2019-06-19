//
// Created by Richard Joseph on 2019-06-01.
//

#include "Space.h"

Space::Space(std::string name, Player *player)
{
    setPlayer(player);
    setName(name);
    top = nullptr;
    right = nullptr;
    bottom = nullptr;
    left = nullptr;
    exit = "Return to the menu";
    std::vector<std::string> spacePrizes;
    spacePrizes.push_back(exit);
    spaceItems = new Menu(spacePrizes);
}

Space::~Space()
{
    delete spaceItems;
}

void Space::setTop(Space *topPtr)
{
    top = topPtr;
}

void Space::setRight(Space *rightPtr)
{
    right = rightPtr;
}

void Space::setBottom(Space *bottomPtr)
{
    bottom = bottomPtr;
}

void Space::setLeft(Space *leftPtr)
{
    left = leftPtr;
}

Space *Space::getTop()
{
    return top;
}

Space *Space::getRight()
{
    return right;
}

Space *Space::getBottom()
{
    return bottom;
}

Space *Space::getLeft()
{
    return left;
}

Player *Space::getPlayer()
{
    return this->player;
}

void Space::setPlayer(Player *user)
{
    this->player = user;
}

void Space::setName(std::string user)
{
    this->name = user;
}

std::string Space::getName()
{
    return this->name;
}
