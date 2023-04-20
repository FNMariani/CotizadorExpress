#include "Item.h"

Item::Item(int stockQuantity, EQuality quality, float unitPrice)
{
    this->stockQuantity = stockQuantity;
    this->quality = quality;
    this->unitPrice = unitPrice;
}

std::string Item::GetItemInfo()
{
    return "";
}

const char* Item::EQualityToString(EQuality e)
{
    switch (e)
    {
        case EQuality::standard: return "Standard";
        case EQuality::premium: return "Premium";
        default: return "Unimplemented item";
    }
}