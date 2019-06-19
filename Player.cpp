//
// Created by Richard Joseph on 2019-06-01.
//

#include "Player.h"

Player::Player()
{
    attackRoll = NULL;
    defenseRoll = NULL;
    attackArray = -1;
    defenseArray = -1;
    strPoints = 0;
    armor = 0;
    charDied = false;
    money = 0;
    hasEnergyDrink = false;
    hasArmor = false;
    hasMirror = false;
    hasSilverSword = false;
    hasStake = false;
}

char Player::getSymbol()
{
    return symbol;
}

void Player::setSymbol(char userIn)
{
    symbol = userIn;
}

void Player::setAttack(int attackIn, int nSides)
{
    attackArray = attackIn;
    attackRoll= new Dice *[attackArray];
    for(int i = 0; i < attackArray;i++)
    {
        attackRoll[i] = new Dice(nSides);
    }
}

void Player::setDefense(int defenseIn, int nSides)
{
    defenseArray = defenseIn;
    defenseRoll = new Dice *[defenseArray];
    for(int i = 0; i < defenseArray; i++)
    {
        defenseRoll[i] = new Dice(nSides);
    }
}

void Player::setArmor(int armorIn)
{
    armor = armorIn;
}

void Player::setStrPoints(int strIn)
{
    strPoints = strIn;
}

int Player::getArmor()
{
    return armor;
}

int Player::getStrPoints()
{
    return strPoints;
}

int Player::attackOpp()
{
    int attackStrength = 0;

    for(int i = 0; i < attackArray; i++)
    {
        attackStrength += attackRoll[i]->rollDie();
    }

    return attackStrength;
}

int Player::defense(int attStrIn)
{
    int defensePts = 0;
    int damage = 0;
    int temp;

    for(int i = 0; i < defenseArray; i++)
    {
        defensePts += defenseRoll[i]->rollDie();
    }

    damage = attStrIn - defensePts - getArmor();
    temp = getStrPoints();

    if(damage >= getStrPoints())
    {
        charDied = true;
        strPoints = 0;

        return temp;
    }

    if(damage > 0)
    {
        strPoints -= damage;
        return damage;
    }

    else
    {
        return 0;
    }
}

bool Player::getDead()
{
    return charDied;
}

Player::~Player()
{
    if ( attackArray > 0 )
    {
        for (int i = 0; i < attackArray; i++)
        {
            delete attackRoll[i];
            attackRoll[i] = NULL;
        }
    }
    if (attackRoll != NULL)
    {
        delete[] attackRoll;
        attackRoll = NULL;
    }
    if ( defenseArray > 0 )
    {
        for (int i = 0; i < defenseArray; i++)
        {
            delete defenseRoll[i];
            defenseRoll[i] = NULL;
        }
    }
    if (defenseRoll != NULL)
    {
        delete[] defenseRoll;
        defenseRoll = NULL;
    }
}

std::string Player::getName()
{
    return name;
}


void Player::setMoney(int startAmount)
{
    money = startAmount;
}

int Player::getMoney()
{
    return money;
}

void Player::seeStats()
{
    std::cout << "Money: " << getMoney() << std::endl;
    std::cout << "Health: " << getStrPoints() << std::endl;
    std::cout << "Attack: " << getAttack() << std::endl;
    std::cout << "Defense: " << getDefense() << std::endl;
    std::cout << "Armor: " << getArmor() << std::endl;
}

int Player::getAttack()
{
    return getAttackArray();
}

int Player::getDefense()
{
    return getDefenseArray();
}

void Player::boughtMirror()
{
    hasMirror = true;
}

void Player::boughtSilver()
{
    hasSilverSword = true;
}

void Player::boughtStake()
{
    hasStake = true;
}

void Player::boughtArmor()
{
    hasArmor = true;
}

void Player::boughtDrink()
{
    hasEnergyDrink = true;
}

bool Player::getMirror()
{
    return hasMirror;
}

bool Player::getSilver()
{
    return hasSilverSword;
}

bool Player::getStake()
{
    return hasStake;
}

bool Player::getVest()
{
    return hasArmor;
}

bool Player::getDrink()
{
    return hasEnergyDrink;
}

void Player::description()
{
    
}

void Player::checkInventory()
{
    std::cout << "Bag capacity: " << bag.getCapacity() << std::endl;
    std::cout << "Bag weight: " << bag.getCurrentWeight() << std::endl;
    std::cout << std::endl;
    bag.dispContents();
    bag.examineItem();
}

bool Player::addToBag(std::shared_ptr<Items> item)
{
    bool addedToBag = bag.addItem(item);
    return addedToBag;
}

void Player::setAttackArray(int userIn)
{
    attackArray = userIn;
}

int Player::getAttackArray()
{
    return attackArray;
}

void Player::setDefenseArray(int userIn)
{
    defenseArray = userIn;
}

int Player::getDefenseArray()
{
    return defenseArray;
}

void Player::setDays(int userIn)
{
    days = userIn;
}

int Player::getDays()
{
    return days;
}

