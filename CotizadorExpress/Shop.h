#pragma once
#include <string>
#include <vector>

#include "Item.h"
#include "Pant.h"
#include "Seller.h"
#include "Shirt.h"

class Shop
{
private:
    std::string name;
    std::string address;

    Seller* seller;

    Item* dummy;
    
public:
    Shop(std::string name, std::string address);
    std::vector<Item> itemsToSell;
    
    float CalculatePrice(Item* item);
    
    std::string GetName() {return name;}
    std::string GetAddress() {return address;}
    
    Seller* GetSeller() {return seller;}
  
    void CreateTestingData();
    void CreateTestingSeller();
    
    void CreateDummy(std::string dummyType);
    
    Item* GetDummy() {return dummy;}
    Shirt* GetDummyCastShirt() {return dynamic_cast<Shirt*>(dummy);}
    Pant* GetDummyCastPant() {return dynamic_cast<Pant*>(dummy);}
};
