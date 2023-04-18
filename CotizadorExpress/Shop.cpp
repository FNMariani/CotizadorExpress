#include "Shop.h"

#include <iostream>

#include "Pant.h"
#include "Shirt.h"

Shop::Shop(std::string name, std::string address)
{
    this->name = name;
    this->address = address;
}

float Shop::CalculatePrice(Item* item)
{
    float tempPrice = item->unitPrice;

    Shirt* _tempShirt = nullptr;
    Pant* _tempPant = nullptr;
    
    //Shop Rules
    if(_tempShirt = dynamic_cast<Shirt*>(item))
    {
        if(_tempShirt->sleeveType == ESleeveType::shortSleeve)
        {
            //Discount 10%
            tempPrice *= 0.9f;
        }

        if(_tempShirt->neckType == ENeckType::maoNeck)
        {
            //Increase 3%
            tempPrice *= 1.03f;
        }
    }
    else if(_tempPant = dynamic_cast<Pant*>(item))
    {
        if(_tempPant->pantType == EPantType::chupinPant)
        {
            //Discount 12%
            tempPrice *= 0.88f;
        }
    }
    else
    {
        std::cout << "El item no corresponde a una camisa o un pantalon." << std::endl;
    }

    if(item->quality == EQuality::premium)
    {
        //Increase 30%
        tempPrice *= 1.3f;
    }

    return tempPrice;
}
