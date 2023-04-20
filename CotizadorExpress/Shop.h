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
    Quote* tempQuote;

    int quoteId = 0;
    
public:
    Shop(std::string name, std::string address);
    std::vector<Item> itemsToSell;
    
    std::string GetName() const {return name;}
    std::string GetAddress() const {return address;}
    
    int GetQuoteId() const {return quoteId;}
    void IncreseQuoteId() {quoteId++;}
    
    Seller* GetSeller() const {return seller;}
  
    void CreateTestingData();
    void CreateTestingSeller();
    
    void CreateDummy(std::string dummyType);
    
    Item* GetDummy() const {return dummy;}
    Shirt* GetDummyCastShirt() const {return dynamic_cast<Shirt*>(dummy);}
    Pant* GetDummyCastPant() const {return dynamic_cast<Pant*>(dummy);}
    
    Quote* GetTempQuote() const {return tempQuote;}
    void CreateTempQuote();

    std::string GetItemInfo() const;
    
    int GetStockFromItem(std::string itemToFind) const;
};
