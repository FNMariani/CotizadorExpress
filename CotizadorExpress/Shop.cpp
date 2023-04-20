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
        tempQuote->listedItem = dummy;
    }
    else if(dummyType == "Pant")
    {
        dummy = new Pant();
        tempQuote->listedItem = dummy;
    }
    else
    {
        std::cout << "ERROR: Bad dummyType!" << std::endl;
    }
}

void Shop::CreateTempQuote()
{
    tempQuote = new Quote(quoteId);
    tempQuote->sellerCode = seller->GetCode();
    seller->GetQuotesHistory().push_back(tempQuote);
}

std::string Shop::GetItemInfo() const
{
    std::string infoItem;
    if(GetDummyCastPant() != nullptr) { infoItem = GetDummyCastPant()->GetItemInfo(); }
    if(GetDummyCastShirt() != nullptr) { infoItem = GetDummyCastShirt()->GetItemInfo(); }

    return infoItem;
}

int Shop::GetStockFromItem(std::string itemToFind) const
{
    if(itemToFind.find("Camisa") != std::string::npos)
    {
        if(itemToFind.find("Short") != std::string::npos)
        {
            if(itemToFind.find("Mao") != std::string::npos)
            {
                if(itemToFind.find("Standard") != std::string::npos)
                {
                    //shirtShortMaoStandard
                    return itemsToSell[0].stockQuantity;
                }
                else
                {
                    //shirtShortMaoPremium
                    return itemsToSell[1].stockQuantity;
                }
            }
            else
            {
                if(itemToFind.find("Standard") != std::string::npos)
                {
                    //shirtShortCommonStandard
                    return itemsToSell[2].stockQuantity;
                }
                else
                {
                    //shirtShortCommonPremium
                    return itemsToSell[3].stockQuantity;
                }
            }
        }
        else
        {
            if(itemToFind.find("Mao") != std::string::npos)
            {
                if(itemToFind.find("Standard") != std::string::npos)
                {
                    //shirtLongMaoStandard
                    return itemsToSell[4].stockQuantity;
                }
                else
                {
                    //shirtLongMaoPremium
                    return itemsToSell[5].stockQuantity;
                }
            }
            else
            {
                if(itemToFind.find("Standard") != std::string::npos)
                {
                    //shirtLongCommonStandard
                    return itemsToSell[6].stockQuantity;
                }
                else
                {
                    //shirtLongCommonPremium
                    return itemsToSell[7].stockQuantity;
                }
            }
        }
    }
    else //Pants
    {
        if(itemToFind.find("Chupin") != std::string::npos)
        {
            if(itemToFind.find("Standard") != std::string::npos)
            {
                //pantChupinStandard
                return itemsToSell[8].stockQuantity;
            }
            else
            {
                //pantChupinPremium
                return itemsToSell[9].stockQuantity;
            }
        }
        else
        {
            if(itemToFind.find("Standard") != std::string::npos)
            {
                //pantCommonStandard
                return itemsToSell[10].stockQuantity;
            }
            else
            {
                //pantCommonPremium
                return itemsToSell[11].stockQuantity;
            }
        }
    }
}