#include "Shirt.h"

Shirt::Shirt(): Item(stockQuantity, quality, unitPrice)
{
    
}

Shirt::Shirt(int stockQuantity, EQuality quality, float unitPrice, ESleeveType sleeveType, ENeckType neckType): Item(stockQuantity, quality, unitPrice)
{
    this->sleeveType = sleeveType;
    this->neckType = neckType;
}
