//
// Created by Richard Joseph on 2019-06-05.
//

#include "Vampire.h"

Vampire::Vampire() : Player()
{
    this->name = "Vampire";
    this->setAttack(1, 12);
    this->attackArray = 1;
    this->setDefense(1, 6);
    this->defenseArray = 1;
    this->setStrPoints(18);
    this->setArmor(1);
    this->setMoney(5000);
}

Vampire::Vampire(std::string user)
{
    this->name = user;
    this->setAttack(1, 12);
    this->attackArray = 1;
    this->setDefense(1, 6);
    this->defenseArray = 1;
    this->setStrPoints(18);
    this->setArmor(1);
}

int Vampire::defense(int attPtsIn)
{
    if(specialAbility())
    {
        return 0;
    }

    else
    {
        return Player::defense(attPtsIn);
    }
}

bool Vampire::specialAbility()
{
    bool worked = false;
    int rolledNum;
    rolledNum = rand() % 2;


    if(rolledNum == 1)
    {
        std::cout << "Vampire had used charm to stop you from attacking" << std::endl;
        worked = true;
    }
    return worked;
}

void Vampire::description()
{
    std::cout << "King of all the monsters make sure you have the correct material before battle." << std::endl;
    std::cout << "This battle will test all of your strength." <<std::endl;
    std::cout << "There are people that have seen him die and come back to life. Does he have any weakness." << std::endl;
    std::cout << "Watch out for his special charm ability which will make you mistake him for an ally." << std::endl;
}
