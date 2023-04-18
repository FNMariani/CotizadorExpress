#include "Presenter.h"
#include <iostream>

Presenter::Presenter(IView* view) : view(view), shop(new Shop("TiendaDeRopa", "221B Baker Street"))
{
    shop->CreateTestingData();
    shop->CreateTestingSeller();
}

Presenter::~Presenter()
{
    shop->itemsToSell.clear();
    delete shop;
}

std::string Presenter::GetShopName() const
{ 
    return shop->GetName();
}

std::string Presenter::GetShopAddress() const
{
    return shop->GetAddress();
}

void Presenter::CreateShirtDummy()
{
    shop->CreateDummy("Shirt");
}

void Presenter::CreatePantDummy()
{
    shop->CreateDummy("Pant");
};
