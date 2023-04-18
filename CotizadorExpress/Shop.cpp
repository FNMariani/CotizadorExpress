#include "Shop.h"

#include <iostream>

#include "Pant.h"
#include "Seller.h"
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

void Shop::CreateTestingData()
{
    //Items for test
    Shirt* shirtShortMaoStandard = new Shirt(100, EQuality::standard, 100, ESleeveType::shortSleeve, ENeckType::maoNeck);
    Shirt* shirtShortMaoPremium = new Shirt(100, EQuality::premium, 100, ESleeveType::shortSleeve, ENeckType::maoNeck);
    Shirt* shirtShortCommonStandard = new Shirt(150, EQuality::standard, 100, ESleeveType::shortSleeve, ENeckType::commonNeck);
    Shirt* shirtShortCommonPremium = new Shirt(150, EQuality::premium, 100, ESleeveType::shortSleeve, ENeckType::commonNeck);

    Shirt* shirtLongMaoStandard = new Shirt(75, EQuality::standard, 100, ESleeveType::longSleeve, ENeckType::maoNeck);
    Shirt* shirtLongMaoPremium = new Shirt(75, EQuality::premium, 100, ESleeveType::longSleeve, ENeckType::maoNeck);
    Shirt* shirtLongCommonStandard = new Shirt(175, EQuality::standard, 100, ESleeveType::longSleeve, ENeckType::commonNeck);
    Shirt* shirtLongCommonPremium = new Shirt(175, EQuality::premium, 100, ESleeveType::longSleeve, ENeckType::commonNeck);

    Pant* pantChupinStandard = new Pant(750, EQuality::standard, 100, EPantType::chupinPant);
    Pant* pantChupinPremium = new Pant(750, EQuality::premium, 100, EPantType::chupinPant);
    Pant* pantCommonStandard = new Pant(250, EQuality::standard, 100, EPantType::commonPant);
    Pant* pantCommonPremium = new Pant(250, EQuality::premium, 100, EPantType::commonPant);
    
    itemsToSell.push_back(*shirtShortMaoStandard);
    itemsToSell.push_back(*shirtShortMaoPremium);
    itemsToSell.push_back(*shirtShortCommonStandard);
    itemsToSell.push_back(*shirtShortCommonPremium);
    itemsToSell.push_back(*shirtLongMaoStandard);
    itemsToSell.push_back(*shirtLongMaoPremium);
    itemsToSell.push_back(*shirtLongCommonStandard);
    itemsToSell.push_back(*shirtLongCommonPremium);
    itemsToSell.push_back(*pantChupinStandard);
    itemsToSell.push_back(*pantChupinPremium);
    itemsToSell.push_back(*pantCommonStandard);
    itemsToSell.push_back(*pantCommonPremium);
}

void Shop::CreateTestingSeller()
{
    seller = new Seller("Ramon", "Sastre", 11);
}

void Shop::CreateDummy(std::string dummyType)
{
    if(dummyType == "Shirt")
    {
        dummy = new Shirt();
    }
    else if(dummyType == "Pant")
    {
        dummy = new Pant();
    }
    else
    {
        std::cout << "ERROR: Bad dummyType!" << std::endl;
    }
}
