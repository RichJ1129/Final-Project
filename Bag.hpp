
#ifndef Bag_hpp
#define Bag_hpp

#include <iostream>
#include "Items.h"
#include <vector>
#include "Menu.h"

class Bag
{
private:
    int capacity;
    int currentWeight;
    std::vector<std::shared_ptr<Items>> bagVector;

public:
    Bag();
    bool addItem(std::shared_ptr<Items> item);
    std::shared_ptr<Items> removeItem();
    void removeVectorItem(std::vector<std::shared_ptr<Items>> &, int itemToRemove);
    void examineItem();
    void dispContents();
    void setCapacity(int);
    int getCapacity();
    void setCurrentWeight(int);
    int getCurrentWeight();
    std::vector<std::shared_ptr<Items>> &getBagVector();
};

#endif /* Bag_hpp */
