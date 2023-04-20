#pragma once
#include <string>

enum EQuality { standard, premium };

class Item
{
public:
    Item(int stockQuantity, EQuality quality, float unitPrice);
    virtual ~Item() = default;
    
    virtual std::string GetItemInfo();
    
    const char* EQualityToString(EQuality e);

    EQuality quality;
    float unitPrice;
    int stockQuantity;
};
