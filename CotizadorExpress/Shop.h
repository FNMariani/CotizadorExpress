#pragma once
#include <string>
#include <vector>

#include "Item.h"

class Shop
{
    std::string name;
    std::string address;
    
public:
    Shop(std::string name, std::string address);
    std::vector<Item> itemsToSell[];
    
    float CalculatePrice(Item* item);
};
