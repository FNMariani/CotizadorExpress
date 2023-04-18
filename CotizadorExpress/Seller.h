#pragma once
#include <string>
#include "Quote.h"

class Seller
{
    std::string name;
    std::string surname;
    int sellerCode;
    
protected:
    //Quote QuotesHistory[];
    
public:
    Seller(std::string name, std::string surname, int sellerCode);
    
    std::string GetName() {return name;}
    std::string GetSurname() {return surname;}
    int GetCode() {return sellerCode;}
};
