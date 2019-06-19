//
// Created by Richard Joseph on 2019-06-05.
//

#include "Game.h"

Game::Game()
{
    hero = new Hero;
    createMap();
    std::vector<std::string> gameInputs;
    gameInputs.push_back("See the Continental Hotel map");
    gameInputs.push_back("See inventory");
    gameInputs.push_back("Move spaces");
    gameInputs.push_back("Enter the current location");
    gameInputs.push_back("See your Stats");
    gameInputs.push_back("Retire");
    gameMenu = new Menu("What would you like to do?", gameInputs);
    std::vector<std::string> spaceInputs;
    spaceInputs.push_back("Return to the main menu");
    spaceMenu = new Menu("Where would you like to go?", spaceInputs);
    startGame();
}

Game::~Game()
{
    delete hero;
    delete gameMenu;
    delete spaceMenu;
    destroyMap();
}

void Game::startGame()
{
    currLocation = base;
    int menuChoice = 0;
    
    do
    {
        menuChoice = gameMenu->showMenu();
        if (menuChoice != 6)
        {
            switch (menuChoice)
            {
                case 1:
                    printMap();
                    break;
                case 2:
                    hero->checkInventory();
                    break;
                case 3:
                    takeTurn();
                    break;
                case 4:
                    currLocation->enterRoom();
                    break;
                case 5:
                    seeStats();
            }
        }
    }
    while (menuChoice != 6 && hero->getDays() >= 0 && hero->getStrPoints() >= 0);
    endGame();
}

void Game::createMap()
{
    base = new Base(hero);
    dojo = new Dojo(hero);
    bedroom = new Bedroom(hero);
    home = new Home(hero);
    store = new Store(hero);

    base->setBottom(dojo);
    dojo->setTop(base);
    dojo->setBottom(bedroom);
    bedroom->setTop(dojo);
    bedroom->setBottom(home);
    home->setTop(bedroom);
    home->setBottom(store);
    store->setTop(home);
}

void Game::destroyMap()
{
    delete base;
    delete dojo;
    delete bedroom;
    delete home;
    delete store;
}

void Game::printMap()
{
    Space *start = base;
    Space *nextRow = start;

    std::cout << "*------------------------------*" << std::endl;

    while (nextRow != nullptr)
    {
        std::string outputName;

        std::cout << '|';
        std::cout << "                              |";
        std::cout << std::endl;


        if(currLocation == nextRow)
        {
            outputName = nextRow->getName() + " (!)";
        }

        else
        {
            outputName = nextRow->getName();
        }

        std::cout << '|' << std::left << " " << std::setw(29) << outputName << '|';
        std::cout << std::endl;
        std::cout << std::setw(31) << '|';
        std::cout << '|' << std::endl;

        std::cout << "*------------------------------*" << std::endl;

        nextRow = nextRow->getBottom();
    }
}

void Game::takeTurn()
{
    std::vector<std::string> spaceMenuItems;
    std::vector<Space*> spaces;
    if (currLocation->getTop() != nullptr)
    {
        spaceMenuItems.push_back(currLocation->getTop()->getName());
        spaces.push_back(currLocation->getTop());
    }

    if (currLocation->getBottom() != nullptr)
    {
        spaceMenuItems.push_back(currLocation->getBottom()->getName());
        spaces.push_back(currLocation->getBottom());
    }

    spaceMenuItems.emplace_back("Return to main menu");
    spaceMenu->setMenuSelections(spaceMenuItems);
    int menuChoice = spaceMenu->showMenu();

    if(menuChoice != spaceMenuItems.size())
    {
        int daysLeft = hero->getDays();
        hero->setDays(daysLeft -1);
        spaces.at(menuChoice - 1);
        currLocation = spaces.at(menuChoice - 1);
    }

    else if(menuChoice == 2)
    {
        gameMenu->showMenu();
    }
}

void Game::endGame()
{
    bool stakeCondition = hero->getStake();
    bool armorCondition = hero->getVest();
    bool drinkCondition = hero->getDrink();
    bool mirrorCondition = hero->getMirror();
    bool silverCondition = hero->getSilver();
    
    if (hero->getStrPoints() <= 0)
    {
        std::cout << "Game over" << std::endl;
    }
    
    
    else if(stakeCondition == true && armorCondition== true && drinkCondition == true && mirrorCondition== true && silverCondition == true)
    {
        std::cout << "You have paid your debt and retired succesfully" << std::endl;
    }

    else
    {
        std::cout << "You have not obtained all 5 items, the Company has decided to eliminate you" << std::endl;
    }
}

void Game::seeStats()
{
    std::cout << "Money: " << hero->getMoney() << std::endl;
    std::cout << "Health: " << hero->getStrPoints() << std::endl;
    std::cout << "Attack: " << hero->getAttack() << std::endl;
    std::cout << "Defense: " << hero->getDefense() << std::endl;
    std::cout << "Days Left: " << hero->getDays() << std::endl;
}


/*
*---------------------*
|                     |
|Base of Operations   |
|                     |
*---------------------*
|                     |
|Dojo                 |
|                     |
*---------------------*
|                     |
|Bedroom              |
|                     |
*---------------------*
|                     |
| Home (Start Here)   |
|                     |
*---------------------*
|                     |
| Store               |
|                     |
*---------------------*
*/
