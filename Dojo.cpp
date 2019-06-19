//
// Created by Richard Joseph on 2019-06-04.
//

#include "Dojo.h"

Dojo::Dojo(Player *player) : Space("Dojo", player)
{
    std::vector<std::string> dojoItems;
    dojoItems.push_back("Train");
    dojoItems.push_back(exit);
    std::string promptText = "Welcome to your Dojo. What would you like to do?";
    spaceItems->setPromptText(promptText);
    spaceItems->setMenuSelections(dojoItems);
}

Dojo::~Dojo()
{}

void Dojo::enterRoom()
{

    int menuChoice;

    menuChoice = spaceItems->showMenu();

    if(menuChoice == 1)
    {
        std::cout << "You had a great training session and trained for 5 days" << std::endl;
        performAction(menuChoice);
    }
}

void Dojo::performAction(int userChoice)
{
    Player *user = this->getPlayer();
    
    int health = player->getStrPoints();
    int days = player->getDays();
    
    player->setStrPoints(health + 5);
    player->setDays(days - 5);
}


