#pragma once
#include "Item.h"

enum ESleeveType { shortSleeve, longSleeve };
enum ENeckType { maoNeck, commonNeck };

class Shirt : public Item
{
public:
    Shirt();
    Shirt(int stockQuantity, EQuality quality, float unitPrice, ESleeveType sleeveType, ENeckType neckType);

    ESleeveType sleeveType;
    ENeckType neckType;
    
    std::string GetItemInfo() override;
    
    const char* EShirtSleeveTypeToString(ESleeveType e);
    const char* EShirtNeckTypeToString(ENeckType e);
};
