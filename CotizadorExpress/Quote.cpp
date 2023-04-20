#include "Quote.h"

#include <iostream>
#include <time.h>

#include "Pant.h"
#include "Shirt.h"

Quote::Quote(int idNumber)
{
    this->idNumber = idNumber;

    UpdateDate();
}

void Quote::UpdateDate()
{
    const size_t  strSize = 255;
    time_t t = time(NULL);

    tm time_now;
    localtime_s(&time_now, &t);

    char cstr[strSize] = "";
    strftime(cstr, strSize, "%d-%m-%Y %H:%M", &time_now);

    std::string str = cstr;
    
    date = str;
}

float Quote::CalculatePrice(Item* item)
{
    float tempPrice = item->unitPrice;
    
    //Shop Rules
    if(Shirt* _tempShirt = dynamic_cast<Shirt*>(item))
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
    else if(Pant* _tempPant = dynamic_cast<Pant*>(item))
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

    totalPrice = tempPrice * quantity;

    return totalPrice;
}