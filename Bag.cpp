//
//  Bag.cpp
//  FinalProject
//
//  Created by Richard Joseph on 6/11/19.
//  Copyright © 2019 Richard Joseph. All rights reserved.
//

#include "Bag.hpp"

Bag::Bag()
{
    capacity = 5;
    this->currentWeight = 0;
}

bool Bag::addItem(std::shared_ptr<Items> item)
{
    if(item == nullptr)
    {
        std::cout << std::endl;
        std::cout << "..." << std::endl << std::endl;
        return false;
    }
    
    int newWeight = item->getWeight() + currentWeight;
    
    if(newWeight <= capacity)
    {
        bagVector.push_back(item);
        currentWeight = newWeight;
      
        std::cout << "Item added to bag: " << item->getName() << std::endl << std::endl;
        
        return true;
    }
    
    return false;
}

std::shared_ptr<Items> Bag::removeItem()
{
    std::vector<std::string> bagMenu;
    for(int i = 0; i < bagVector.size(); i++)
    {
        std::string bagName = bagVector[i]->getName();
        bagMenu.push_back(bagName);
    }
    
    if(bagVector.empty())
    {
        std::cout << "Your backpack is empty." << std::endl << std::endl;
        return nullptr;
    }
    
    int menuChoice;
    
    
    std::cout << "Choose an Item" << std::endl;
    std::cout << std::endl;
    
    if (menuChoice == 0)
    {
        return nullptr;
    }
    
    std::shared_ptr<Items> itemToRemove = bagVector[menuChoice - 1];
    
    currentWeight = currentWeight - itemToRemove->getWeight();
    
    std::cout << "Item removed from bag: " << itemToRemove->getName() << std::endl << std::endl;
    
    return itemToRemove;
}

void Bag::setCapacity(int capacity)
{
    this->capacity = capacity;
}

int Bag::getCapacity()
{
    return capacity;
}

void Bag::setCurrentWeight(int userIn)
{
    this->currentWeight = userIn;
}

int Bag::getCurrentWeight()
{
    return currentWeight;
}

std::vector<std::shared_ptr<Items>>& Bag::getBagVector()
{
    return bagVector;
}

void Bag::dispContents()
{
    std::cout << "Inventory Contents" << std::endl;
    std::cout << "***********************" << std::endl;
    
    for(int i = 0; i < bagVector.size(); i++)
    {
        std::cout << "Item " << i + 1<<": " << bagVector[i]->getName() << std::endl;
    }
    
    if(bagVector.empty())
    {
        std::cout << "Bag is empty" << std::endl << std::endl;
    }
    
    else
    {
        std::cout << std::endl;
    }
    
    std::cout << "***********************" << std::endl;
}

void Bag::examineItem()
{
    if(!bagVector.empty())
    {
        std::cout << "Which Item would you like to examine?" << std::endl;
        
        int userchoice = inputValidation(1, bagVector.size());
        
        bagVector[userchoice - 1]->getName();
        std::cout << std::endl;
        bagVector[userchoice - 1]->itemDescription();
        
        std::cout << "Would you like to delete this Item?" << std::endl;
        std::cout << "1:Yes" << std::endl;
        std::cout << "2:No" << std::endl;
        int playerChoice = inputValidation(1, 2);
        
        if(playerChoice == 1)
        {
            removeVectorItem(bagVector, userchoice - 1);
            
            currentWeight -= 1;
        }
        
        else
        {
            
        }
    }

}

void Bag::removeVectorItem(std::vector<std::shared_ptr<Items>> &vector, int itemToRemove)
{
    vector[itemToRemove] = nullptr;
    
    std::vector<std::shared_ptr<Items>> temp;
    for(int i = 0; i < vector.size(); i++)
    {
        if (vector[i] != nullptr)
        {
            temp.push_back(vector[i]);
        }
    }
    
    vector.clear();
    std::vector<std::shared_ptr<Items>>(vector).swap(vector);
    
    for(int i = 0; i < temp.size(); i++)
    {
        vector.push_back(temp[i]);
    }

}
