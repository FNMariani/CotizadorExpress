#pragma once
#include <string>
#include "Quote.h"

class Seller
{
    std::string name;
    std::string surname;
    
protected:
    int sellerCode;
    //Quote QuotesHistory[];
    
public:
    Seller(std::string name, std::string surname, int sellerCode);
};
