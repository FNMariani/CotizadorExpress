#pragma once
#include <string>
#include <vector>

#include "Quote.h"

class Seller
{
    std::string name;
    std::string surname;
    int sellerCode;
    std::vector<Quote*> quotesHistory;
    
public:
    Seller(std::string name, std::string surname, int sellerCode);
    
    std::string GetName() {return name;}
    std::string GetSurname() {return surname;}
    int GetCode() {return sellerCode;}

    std::vector<Quote*> &GetQuotesHistory() {return quotesHistory;}
};
