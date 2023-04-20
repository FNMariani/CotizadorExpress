#pragma once
#include <string>
#include "Item.h"

class Quote
{
    int idNumber;
    std::string date;
    
public:
    Quote(int idNumber);
    int sellerCode;
    int quantity;
    float totalPrice;
    Item* listedItem;

    void UpdateDate();
    
    float CalculatePrice(Item* item);

    std::string GetDate() const {return date;}
    int GetIdNumber() const {return idNumber;}
    
    Item* GetListedItem() {return listedItem;}
};
