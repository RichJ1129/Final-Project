//
// Created by Richard Joseph on 2019-06-01.
//

#include "Home.h"


Home::Home(Player *player) : Space("Continental Hotel", player)
{

}

Home::~Home()
{

}

void Home::enterRoom()
{
    std::cout << "Welcome to the Continental Hotel" << std::endl;
}

void Home::performAction(int userChoice)
{

}



