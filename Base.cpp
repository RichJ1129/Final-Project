//
// Created by Richard Joseph on 2019-06-04.
//

#include "Base.h"


Base::Base(Player *player) : Space("Base of Operations", player)
{
    std::vector<std::string> baseItems;
    baseItems.push_back("Recon Targets");
    baseItems.push_back("Select targets and start mission");
    baseItems.push_back(exit);
    std::string promptText = "Welcome to your Base of Operations. What would you like to do?";
    spaceItems->setPromptText(promptText);
    spaceItems->setMenuSelections(baseItems);
}

Base::~Base()
{

}

void Base::enterRoom()
{
    int menuChoice;

    menuChoice = spaceItems->showMenu();

    if(menuChoice == 1)
    {
        std::cout << "Who would you like to perform reconnaissance on?" << std::endl;
        performAction(menuChoice);
    }

    else if(menuChoice == 2)
    {
        std::cout << "Select your target from below to start your mission" << std::endl;
        performAction(menuChoice);
    }

}

void Base::performAction(int userChoice)
{
    Player *gargoyle = new Gargoyle;
    Player *vampire = new Vampire;
    Player *medusa = new Medusa;
    Player *blueMen = new BlueMen;
    

    if(userChoice == 1)
    {
        std::cout << "1: Gargoyle" << std::endl;
        std::cout << "2: Vampire" << std::endl;
        std::cout << "3: Medusa" << std::endl;
        std::cout << "4: Blue Men" << std::endl;


        int functionChoices = inputValidation(1, 4);

        if(functionChoices == 1)
        {
            gargoyle->seeStats();
        }

        else if(functionChoices == 2)
        {
            vampire->seeStats();
        }

        else if(functionChoices == 3)
        {
            medusa->seeStats();
        }
        
        else if(functionChoices == 4)
        {
            blueMen->seeStats();
        }
    }

    else if(userChoice == 2)
    {
        std::cout << "1: Gargoyle" << std::endl;
        std::cout << "2: Vampire" << std::endl;
        std::cout << "3: Medusa" << std::endl;
        std::cout << "4: Blue Men" << std::endl;

        int functionChoices = inputValidation(1, 4);

        if(functionChoices == 1)
        {
            std::cout << "You have approached the Gargoyle to fight" << std::endl;
            fightOpponent(player, gargoyle);
        }

        else if(functionChoices == 2)
        {
            std::cout << "You have approached the Vampire to fight" << std::endl;
            fightOpponent(player, vampire);
        }

        else if(functionChoices == 3)
        {
            std::cout << "You have approached Medusa to fight" << std::endl;
            fightOpponent(player, medusa);
        }
        else if(functionChoices == 4)
        {
            std::cout << "You have approached the Blue Men to fight" << std::endl;
            fightOpponent(player, blueMen);
        }
    }

    else if(userChoice == 3)
    {

    }
}

Player *Base::fightOpponent(Player *p1, Player *p2)
{
    while(!p1->getDead() && !p2->getDead())
    {
        int damageToP1;
        int damageToP2;
        std::cout << "Attacker Type: " << p1->getName() << std::endl;
        std::cout << "Defender Type: " << p2->getName() << std::endl;
        std::cout << "Defender armor: " << p2->getArmor() << std::endl;
        std::cout << "Defender Strength: " << p2->getStrPoints() << std::endl;
        damageToP2 = p2->defense(p1->attackOpp());
        std::cout << "Total Damage: "  << damageToP2 << " pts" << std::endl;
        std::cout << "Defenders strength is now: " << p2->getStrPoints() << std::endl;
        
        if(p2->getDead() == true)
        {
            break;
        }
        
        std::cout << "Attacker Type: " << p2->getName() << std::endl;
        std::cout << "Defender Type: " << p1->getName() << std::endl;
        std::cout << "Defender armor: " << p1->getArmor() << std::endl;
        std::cout << "Defender Strength: " << p1->getStrPoints() << std::endl;
        damageToP1 = p1->defense(p2->attackOpp());
        std::cout << "Total Damage: "  << damageToP1 << " pts" << std::endl;
        std::cout << "Defenders strength is now: " << p1->getStrPoints() << std::endl;
    }
    
    if(p1->getDead())
    {
        std::cout << p2->getName() << " has won the battle: " << p2->getName() << std::endl;
        std::cout << "Training more in the Dojo will help you defeat the enemy" << std::endl;
        return p2;
    }
    
    else
    {
        std::cout << "You have won the battle" << std::endl;
        int money = player->getMoney();
        int enemyMoney = p2->getMoney();
        player->setMoney(money + enemyMoney);
        return p1;
    }
}
