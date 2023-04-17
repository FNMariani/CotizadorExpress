#include "Item.h"

Item::Item(int stockQuantity, EQuality quality, float unitPrice)
{
    this->stockQuantity = stockQuantity;
    this->quality = quality;
    this->unitPrice = unitPrice;
}
