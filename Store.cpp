//
// Created by Richard Joseph on 2019-06-04.
//

#include "Store.h"

Store::Store(Player *player) : Space("Concierge Desk", player)
{
    std::vector<std::string> storeItems;
    storeItems.push_back("Buy Armor             Price: 1000");
    storeItems.push_back("Buy Stake             Price: 1000");
    storeItems.push_back("Buy Energy Drink      Price: 1000");
    storeItems.push_back("Buy Silver Sword      Price: 1000");
    storeItems.push_back("Buy Mirror            Price: 1000");
    storeItems.push_back(exit);
    std::string promptText = "Welcome to the Concierge Desk. What would you like to purchase? Each Item will be consumed immediately after purchase";
    spaceItems->setPromptText(promptText);
    spaceItems->setMenuSelections(storeItems);
}

void Store::enterRoom()
{
    Player *user = this->getPlayer();

    int menuChoice;

    int money = user->getMoney();
    

    menuChoice = spaceItems->showMenu();

    if(menuChoice == 1 && money >= 0)
    {
        std::cout << "A vest has been added to your inventory" << std::endl;
        std::shared_ptr<Armor> armor = std::make_shared<Armor>();
        user->setMoney(money - 1000);
        user->addToBag(armor);
        user->boughtArmor();
    }

    else if(menuChoice == 2 && money >= 1000)
    {
        std::cout << "A stake has been added to your inventory." << std::endl;
        std::shared_ptr<Stake> stake = std::make_shared<Stake>();
        user->setMoney(money - 1000);
        user->addToBag(stake);
        user->boughtStake();
    }

    else if(menuChoice == 3 && money >= 1000)
    {
        std::cout << "An energy drink has been added to your inventory. Interesting choice." << std::endl;
        std::shared_ptr<EnergyDrink> energy = std::make_shared<EnergyDrink>();
        user->setMoney(money - 1000);
        user->addToBag(energy);
        user->boughtDrink();
        
    }

    else if(menuChoice == 4 && money >= 1000)
    {
        std::cout << "A silver sword has been added to your inventory." << std::endl;
        std::shared_ptr<SilverSword> silver = std::make_shared<SilverSword>();
        user->setMoney(money - 1000);
        user->addToBag(silver);
        user->boughtSilver();
    }

    else if(menuChoice == 5 && money >= 1000)
    {
        std::cout << "A mirror has been added to your inventory. Pretty vain of you." << std::endl;
        std::shared_ptr<Mirror> mirror = std::make_shared<Mirror>();
        user->setMoney(money - 1000);
        user->addToBag(mirror);
        user->boughtMirror();
    }

    else
    {
        std::cout << "You do not have enough money to purchase the item" << std::endl;
    }
}

Store::~Store()
{

}

void Store::performAction(int userChoice)
{

}
