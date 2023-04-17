#include "Pant.h"

Pant::Pant(int stockQuantity, EQuality quality, float unitPrice, EPantType pantType): Item(stockQuantity, quality, unitPrice)
{
    this->pantType = pantType;
}
