#pragma once
#include "IView.h"
#include "Shop.h"

class Presenter
{
private:
    IView* view = nullptr;
    Shop* shop = nullptr;
    
public:
    Presenter(IView* view);
    ~Presenter();
    
    Shop* GetShop() {return shop;}
    
    std::string GetShopName() const;
    std::string GetShopAddress() const;
    
    void CreateShirtDummy();
    void CreatePantDummy();
};
