//
// Created by Richard Joseph on 2019-06-01.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include <string>
#include "Dice.h"
#include "Bag.hpp"

class Player
{
protected:
    std::string name;
    Dice **attackRoll;
    Dice **defenseRoll;
    int attackArray;
    int defenseArray;
    int strPoints;
    int armor;
    char symbol;
    int money;
    Bag bag;
    bool charDied;
    bool hasMirror;
    bool hasEnergyDrink;
    bool hasArmor;
    bool hasStake;
    bool hasSilverSword;
    int days;

public:
    Player();
    virtual ~Player();
    void setAttack(int, int);
    char getSymbol();
    void setSymbol(char);
    std::string getName();
    void setDefense(int, int);
    int getDefense();
    void setArmor(int);
    int getArmor();
    void setStrPoints(int);
    int getStrPoints();
    bool getDead();
    virtual int attackOpp();
    virtual int defense(int);
    void setMoney(int);
    int getMoney();
    void seeStats();
    int getAttack();
    virtual void description();
    void boughtMirror();
    void boughtStake();
    void boughtSilver();
    void boughtArmor();
    void boughtDrink();
    bool getMirror();
    bool getStake();
    bool getSilver();
    bool getVest();
    bool getDrink();
    void checkInventory();
    bool addToBag(std::shared_ptr<Items>);
    Bag *getBag();
    void setAttackArray(int);
    int getAttackArray();
    void setDefenseArray(int);
    int getDefenseArray();
    int getDays();
    void setDays(int);
};


#endif //FINALPROJECT_PLAYER_H
