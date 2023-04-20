#include "Shirt.h"

Shirt::Shirt(): Item(stockQuantity, quality, unitPrice)
{
    
}

Shirt::Shirt(int stockQuantity, EQuality quality, float unitPrice, ESleeveType sleeveType, ENeckType neckType): Item(stockQuantity, quality, unitPrice)
{
    this->sleeveType = sleeveType;
    this->neckType = neckType;
}

Shirt::~Shirt()
{
    
}

std::string Shirt::GetItemInfo()
{
    std::string info = "";

    info += "Camisa - ";
    info += EShirtSleeveTypeToString(sleeveType);
    info +=  " - ";
    info += EShirtNeckTypeToString(neckType);
    info +=  " - ";
    info += EQualityToString(quality);
    
    return info;
}

const char* Shirt::EShirtSleeveTypeToString(ESleeveType e)
{
    switch (e)
    {
        case ESleeveType::shortSleeve: return "Short";
        case ESleeveType::longSleeve: return "Long";
        default: return "Unimplemented item";
    }
}

const char* Shirt::EShirtNeckTypeToString(ENeckType e)
{
    switch (e)
    {
        case ENeckType::maoNeck: return "Mao";
        case ENeckType::commonNeck: return "Common";
        default: return "Unimplemented item";
    }
}
