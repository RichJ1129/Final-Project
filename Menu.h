//
// Created by Richard Joseph on 2019-06-03.
//

#ifndef FINALPROJECT_MENU_H
#define FINALPROJECT_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "InputValidation.h"

class Menu
{
private:
    std::vector<std::string> menuSelections;
    std::string promptText;

public:
    Menu(std::vector<std::string>);
    Menu(std::string, std::vector<std::string>);
    int showMenu();
    void setPromptText(std::string);
    std::string getPromptText();
    void setMenuSelections(std::vector<std::string>);
};


#endif //FINALPROJECT_MENU_H
