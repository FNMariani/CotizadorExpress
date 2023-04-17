#pragma once

enum EQuality { standard, premium };

class Item
{
public:
    Item(int stockQuantity, EQuality quality, float unitPrice);
    virtual ~Item() = default;
    
    EQuality quality;
    float unitPrice;
    int stockQuantity;
};
