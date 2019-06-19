//
// Created by Richard Joseph on 2019-06-03.
//

#include "Menu.h"

Menu::Menu(std::vector<std::string> items)
{
    setMenuSelections(items);
    setPromptText("");
}

Menu::Menu(std::string text, std::vector<std::string> items)
{
    setMenuSelections(items);
    setPromptText(text);
}


void Menu::setMenuSelections(std::vector<std::string> items)
{
    menuSelections.clear();

    for(auto i : items) //Range based for loop
    {
        menuSelections.push_back(i);
    }
}

void Menu::setPromptText(std::string text)
{
    promptText = text;
}

std::string Menu::getPromptText()
{
    return promptText;
}

int Menu::showMenu()
{
    int choice = 0;

    if(getPromptText() != "")
    {
        std::cout << std::endl << getPromptText() << std::endl;
    }

    for(int i = 0; i < menuSelections.size(); i++)
    {
        std::cout << i + 1 << ". " << menuSelections[i] << std::endl;
    }

    choice = inputValidation(1, menuSelections.size());

    return choice;
}
