//
// Created by Richard Joseph on 2019-06-04.
//

#include "Bedroom.h"

Bedroom::Bedroom(Player *player) : Space("Bedroom", player)
{
    std::vector<std::string> brItems;
    brItems.push_back("Sleep");
    brItems.push_back(exit);
    std::string promptText = "Welcome to your bedroom. What would you like to do?";
    spaceItems->setPromptText(promptText);
    spaceItems->setMenuSelections(brItems);
}

Bedroom::~Bedroom()
{

}

void Bedroom::enterRoom()
{
    int menuChoice;

    menuChoice = spaceItems->showMenu();

    if(menuChoice == 1)
    {
        std::cout << "You recieved 8 hours of sleep and your health has been restored to 100" << std::endl;
        performAction(menuChoice);
    }
}

void Bedroom::performAction(int userChoice)
{
    player->setStrPoints(100);
}
