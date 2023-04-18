#include "Pant.h"

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
