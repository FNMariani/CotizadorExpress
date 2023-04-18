
#include <iostream>

#include "View.h"
#include "Pant.h"
#include "Seller.h"
#include "Shirt.h"
#include "Shop.h"

int main(int argc, char* argv[])
{
    Shop* shop = new Shop("TiendaDeRopa", "221B Baker Street ");
    Seller* seller = new Seller("Ramon", "Sastre", 11);
    
    View* view = new View();

    //Initial items
    Shirt* shirtShortMaoStandard = new Shirt(100, EQuality::standard, 100, ESleeveType::shortSleeve, ENeckType::maoNeck);
    Shirt* shirtShortMaoPremium = new Shirt(100, EQuality::premium, 100, ESleeveType::shortSleeve, ENeckType::maoNeck);
    Shirt* shirtShortCommonStandard = new Shirt(150, EQuality::standard, 100, ESleeveType::shortSleeve, ENeckType::commonNeck);
    Shirt* shirtShortCommonPremium = new Shirt(150, EQuality::premium, 100, ESleeveType::shortSleeve, ENeckType::commonNeck);

    Shirt* shirtLongMaoStandard = new Shirt(75, EQuality::standard, 100, ESleeveType::longSleeve, ENeckType::maoNeck);
    Shirt* shirtLongMaoPremium = new Shirt(75, EQuality::premium, 100, ESleeveType::longSleeve, ENeckType::maoNeck);
    Shirt* shirtLongCommonStandard = new Shirt(175, EQuality::standard, 100, ESleeveType::longSleeve, ENeckType::commonNeck);
    Shirt* shirtLongCommonPremium = new Shirt(175, EQuality::premium, 100, ESleeveType::longSleeve, ENeckType::commonNeck);

    Pant* pantChupinStandard = new Pant(750, EQuality::standard, 100, EPantType::chupinPant);
    Pant* pantChupinPremium = new Pant(750, EQuality::premium, 100, EPantType::chupinPant);
    Pant* pantCommonStandard = new Pant(250, EQuality::standard, 100, EPantType::commonPant);
    Pant* pantCommonPremium = new Pant(250, EQuality::premium, 100, EPantType::commonPant);

    shop->itemsToSell->push_back(*shirtShortMaoStandard);
    shop->itemsToSell->push_back(*shirtShortMaoPremium);
    shop->itemsToSell->push_back(*shirtShortCommonStandard);
    shop->itemsToSell->push_back(*shirtShortCommonPremium);
    shop->itemsToSell->push_back(*shirtLongMaoStandard);
    shop->itemsToSell->push_back(*shirtLongMaoPremium);
    shop->itemsToSell->push_back(*shirtLongCommonStandard);
    shop->itemsToSell->push_back(*shirtLongCommonPremium);
    shop->itemsToSell->push_back(*pantChupinStandard);
    shop->itemsToSell->push_back(*pantChupinPremium);
    shop->itemsToSell->push_back(*pantCommonStandard);
    shop->itemsToSell->push_back(*pantCommonPremium);
    
    delete seller;
    delete shop;
    delete view;
    
    return 0;
}
