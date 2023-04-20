#include "Pant.h"

#include <string>

Pant::Pant(): Item(stockQuantity, quality, unitPrice)
{
    
}

Pant::Pant(int stockQuantity, EQuality quality, float unitPrice, EPantType pantType): Item(stockQuantity, quality, unitPrice)
{
    this->pantType = pantType;
}

Pant::~Pant()
{
}

std::string Pant::GetItemInfo()
{
    std::string info = "";

    info += "Pantalon - ";
    info += EPantTypeToString(pantType);
    info +=  " - ";
    info += EQualityToString(quality);
    
    return info;
}

const char* Pant::EPantTypeToString(EPantType e)
{
    switch (e)
    {
        case EPantType::commonPant: return "Common";
        case EPantType::chupinPant: return "Chupin";
        default: return "Unimplemented item";
    }
}
