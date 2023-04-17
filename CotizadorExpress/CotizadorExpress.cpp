
#include <iostream>

#include "Model.h"
#include "Pant.h"
#include "Shirt.h"

int main(int argc, char* argv[])
{
    Model* model = new Model();

    Shirt* a = new Shirt(10, EQuality::premium, 1, ESleeveType::shortSleeve, ENeckType::maoNeck);
    std::cout << "Shirt: " << model->CalculatePrice(a) << std::endl;

    Pant* b = new Pant(10, EQuality::standard, 1, EPantType::chupinPant);
    std::cout << "Pant: " << model->CalculatePrice(b) << std::endl;

    delete a;
    delete b;
    delete model;
    
    return 0;
}
