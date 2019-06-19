
#include "BlueMen.h"

BlueMen::BlueMen()
{
    this->name = "Barbarian";
    this->setAttack(2, 6);
    this->attackArray = 2;
    this->setDefense(2, 6);
    this->defenseArray = 2;
    this->setStrPoints(15);
    this->setArmor(0);
    this->setMoney(100);
}

BlueMen::BlueMen(std::string user)
{
    this->name = user;
    this->setAttack(2, 6);
    this->attackArray = 2;
    this->setDefense(2, 6);
    this->defenseArray = 2;
    this->setStrPoints(12);
    this->setArmor(0);
}

void BlueMen::description()
{
    std::cout << "A swarm of small creatures that form to create a massive goliath" << std::endl;
    std::cout << "Gets significantly weaker as the battle goes on" << std::endl;
}
