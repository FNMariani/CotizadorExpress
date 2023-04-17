#pragma once
#include "Item.h"

enum EPantType { commonPant, chupinPant };

class Pant : public Item
{
public:
    Pant(int stockQuantity, EQuality quality, float unitPrice, EPantType pantType);

    EPantType pantType;    
};
