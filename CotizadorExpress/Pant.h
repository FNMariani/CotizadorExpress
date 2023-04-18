#pragma once
#include "Item.h"

enum EPantType { commonPant, chupinPant };

class Pant : public Item
{
public:
    Pant();
    Pant(int stockQuantity, EQuality quality, float unitPrice, EPantType pantType);
    ~Pant() override;

    EPantType pantType;    
};
