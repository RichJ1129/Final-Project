#include <iostream>
#include "Space.h"
#include "Player.h"
#include "Home.h"
#include "Player.h"
#include "Hero.h"
#include "Dojo.h"
#include "Bedroom.h"
#include "Base.h"
#include "Home.h"
#include "Store.h"
#include "Game.h"
#include "InputValidation.h"

int main()
{

    srand(time(NULL));
    
    std::cout << "                            Instructions" << std::endl;
    std::cout << "******************************************************************************************************" << std::endl;
    std::cout << "You have lived your life working for The Company and it's time to retire. \n"
                 "There is one caveat no one retires from The Company without any cost. \n"
                 "To retire you must buy five items from the Concierce desk to succesfully within a year. \n"
                 "The five items are: an energy drink, a silver sword, a stake, a mirror, and armor. \n"
                 "You have zero dollars to your name and the only way to get money is to complete monster contracts. \n"
    "Once you have boought each item you can retire succesfully. Consider each move you make takes up a day." << std::endl;
    std::cout << "*******************************************************************************************************" << std::endl;
    std::cout << std::endl;
    
    std::vector<std::string> mainMenuItems = {"Play", "Exit"};
    
    Menu mainMenu(mainMenuItems);
    int menuChoice = 1;
    do
    {
        menuChoice = mainMenu.showMenu();
        if(menuChoice != 2)
        {
            Game simulation;
            mainMenuItems[0] = "Play again";
            mainMenuItems[1] = "Exit";
            mainMenu.setMenuSelections(mainMenuItems);
        }
    }
    while (menuChoice != 2);

    return 0;
}
