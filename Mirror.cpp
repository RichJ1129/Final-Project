//
// Created by Richard Joseph on 2019-06-10.
//

#include "Mirror.h"

Mirror::Mirror() : Items()
{
    setName("Mirror");
    setCost(1000);
    setWeight(1);
}

Mirror::~Mirror()
{

}

void Mirror::itemDescription()
{
    std::cout << "Ordinary mirror. Must have some utility to be found in the store" << std::endl;
}


