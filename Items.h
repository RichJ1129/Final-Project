//
// Created by Richard Joseph on 2019-06-04.
//

#ifndef FINALPROJECT_ITEMS_H
#define FINALPROJECT_ITEMS_H

#include <iostream>
#include <string>
#include <memory>

class Player;

class Items
{
protected:
    std::string name;
    int cost = 0;
    int weight = 0;

public:
    Items();
    virtual ~Items();
    void setName(std::string);
    std::string getName();
    void setCost(int);
    int getCost();
    void setWeight(int);
    int getWeight();
    virtual void itemDescription();
    //virtual void itemAction(Player *) = 0;
    //virtual void buyItem();
};


#endif //FINALPROJECT_ITEMS_H
