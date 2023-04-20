#include "View.h"

#include <iomanip>
#include <iostream>
#include <string>

View::View()
{
    presenter = new Presenter(this);
    showMainMenu();
}

View::~View()
{
    delete presenter;
}

void View::showMainMenu()
{
    std::string option;
	bool exitCondition = false;

    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << presenter->GetShopName() << " | " << presenter->GetShopAddress() << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Seller Name: " << presenter->GetShop()->GetSeller()->GetName() << " " << presenter->GetShop()->GetSeller()->GetSurname() << " | Seller ID: " << presenter->GetShop()->GetSeller()->GetCode() << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "SELECCIONE UNA OPCION DEL MENU: " << std::endl;
        std::cout << std::endl;
        std::cout << "1) Historial de Cotizaciones " << std::endl;
        std::cout << "2) Realizar Cotizacion " << std::endl;
        std::cout << "3) Salir" << std::endl;
        std::cout << std::endl;

        std::cin >> option;
        std::system("cls");

        checkMainOption(option, exitCondition);
        
    } while (!exitCondition);
}

void View::checkHistoryOption(const std::string& option, bool& exitCondition)
{
    if (option == "3")
    {
        std::cout.flush();
        exitCondition = true;
    }
    else
    {
        std::cout << "Opcion ingresada incorrecta, intente nuevamente..." << std::endl;
        std::cin.get();
        exitCondition = false;
    }
}

void View::showHistoryMenu()
{
    std::string option;
	bool exitCondition = false;
    
    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;

        auto quotesHistory = presenter->GetQuotesHistory();
        
        for (const auto& quote : quotesHistory)
        {
            std::cout << "Numero de identificacion: " << quote->GetIdNumber() << std::endl;
            std::cout << "Fecha y Hora de la cotizacion: " << quote->GetDate() << std::endl;
            std::cout << "Codigo del Vendedor: " << quote->sellerCode << std::endl;
            std::cout << "Prenda cotizada: " << quote->GetListedItem()->GetItemInfo() << std::endl;
            std::cout << "Precio Unitario: " << quote->GetListedItem()->unitPrice << std::endl;
            std::cout << "Cantidad de unidades cotizadas: " << presenter->GetShop()->GetTempQuote()->quantity << std::endl;
            std::cout << "Precio Final: " << quote->totalPrice << std::endl;
            std::cout << "" << std::endl;
        }
        
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;

        std::cin >> option;

        checkHistoryOption(option, exitCondition);
        
    } while (!exitCondition);

    showMainMenu();
}

void View::checkSleeveOption(const std::string& option, bool& exitCondition)
{
    if (option == "1")
    {
        //Manga Corta
        presenter->GetShop()->GetDummyCastShirt()->sleeveType = ESleeveType::shortSleeve;
        exitCondition = true;
    }
    else if (option == "2")
    {
        //Manga Larga
        presenter->GetShop()->GetDummyCastShirt()->sleeveType = ESleeveType::longSleeve;
        exitCondition = true;
    }
    else if (option == "3")
    {
        std::cout.flush();
        exitCondition = true;
    }
    else
    {
        std::cout << "Opcion ingresada incorrecta, intente nuevamente..." << std::endl;
        std::cin.get();
        exitCondition = false;
    }
}

void View::showShirtSleeveMenu()
{
    std::string option;
	bool exitCondition = false;
    
    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Paso 2.a: La camisa a cotizar, ¿Es manga corta? " << std::endl;
        std::cout << std::endl;
        std::cout << "1) Si " << std::endl;
        std::cout << "2) No " << std::endl;

        std::cin >> option;
        
        checkSleeveOption(option, exitCondition);
        
    } while (!exitCondition);
}

void View::checkNeckOption(const std::string& option, bool& exitCondition)
{
    if (option == "1")
    {
        //Cuello Mao
        presenter->GetShop()->GetDummyCastShirt()->neckType = ENeckType::maoNeck;
        exitCondition = true;
    }
    else if (option == "2")
    {
        //Cuello comun
        presenter->GetShop()->GetDummyCastShirt()->neckType = ENeckType::commonNeck;
        exitCondition = true;
    }
    else if (option == "3")
    {
        std::cout.flush();
        exitCondition = true;
    }
    else
    {
        std::cout << "Opcion ingresada incorrecta, intente nuevamente..." << std::endl;
        std::cin.get();
        exitCondition = false;
    }
}

void View::showShirtNeckMenu()
{
    std::string option;
	bool exitCondition = false;

    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Paso 2.b: La camisa a cotizar, ¿Es cuello Mao? " << std::endl;
        std::cout << std::endl;
        std::cout << "1) Si " << std::endl;
        std::cout << "2) No " << std::endl;

        std::cin >> option;

        checkNeckOption(option, exitCondition);
        
    } while (!exitCondition);
}

void View::checkPantOption(const std::string& option, bool& exitCondition)
{
    if (option == "1")
    {
        //Chupin
        presenter->GetShop()->GetDummyCastPant()->pantType = EPantType::chupinPant;
        exitCondition = true;
    }
    else if (option == "2")
    {
        //Comun
        presenter->GetShop()->GetDummyCastPant()->pantType = EPantType::commonPant;
        exitCondition = true;
    }
    else if (option == "3")
    {
        std::cout.flush();
        exitCondition = true;
    }
    else
    {
        std::cout << "Opcion ingresada incorrecta, intente nuevamente..." << std::endl;
        std::cin.get();
        exitCondition = false;
    }
}

void View::showPantMenu()
{
    std::string option;
	bool exitCondition = false;

    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Paso 2: El pantalon a cotizar, ¿Es Chupin? " << std::endl;
        std::cout << std::endl;
        std::cout << "1) Si " << std::endl;
        std::cout << "2) No " << std::endl;

        std::cin >> option;

        checkPantOption(option, exitCondition);
        
    } while (!exitCondition);
}

void View::checkQualityOption(const std::string& option, bool& exitCondition)
{
    if (option == "1")
    {
        //Standard
        presenter->GetShop()->GetDummy()->quality = EQuality::standard;
        exitCondition = true;
    }
    else if (option == "2")
    {
        //Premium
        presenter->GetShop()->GetDummy()->quality = EQuality::premium;
        exitCondition = true;
    }
    else if (option == "3")
    {
        std::cout.flush();
        exitCondition = true;
    }
    else
    {
        std::cout << "Opcion ingresada incorrecta, intente nuevamente..." << std::endl;
        std::cin.get();
    }
}

void View::showQualityMenu()
{
    std::string option;
	bool exitCondition = false;

    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Paso 3: Selecione la calidad de la prenda " << std::endl;
        std::cout << std::endl;
        std::cout << "1) Standard " << std::endl;
        std::cout << "2) Premium " << std::endl;

        std::cin >> option;

        checkQualityOption(option, exitCondition);
        
    } while (!exitCondition);
}

void View::checkUnitPriceInput(const std::string& option, bool& exitCondition)
{
    if (option == "3")
    {
        std::cout.flush();
    }
    else
    {
        presenter->GetShop()->GetDummy()->unitPrice = std::stof(option);
    }
    
    exitCondition = true;
}

void View::showUnitPriceMenu()
{
    std::string option;
	bool exitCondition = false;

    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Paso 4: Ingrese el precio unitario de la prenda a cotizar (con un decimal al menos. Ej.: 10.5)" << std::endl;
        std::cout << std::endl;

        std::cin >> option;
        
        checkUnitPriceInput(option, exitCondition);
        
    } while (!exitCondition);
}

void View::checkQuantityInput(const std::string& option, int stockToCompare, bool& exitCondition)
{
    int optionInt = std::stoi(option);
    
    if(optionInt <= stockToCompare)
    {
        presenter->GetShop()->GetTempQuote()->quantity = optionInt;
        exitCondition = true;
    }
    else
    {
        std::cout << "ERROR: Valor a cotizar mayor al stock actual, intente nuevamente..." << std::endl;
        std::cin.get();
        std::cin.get();
        exitCondition = false;
    }
}

void View::showQuantityMenu()
{
    std::string option;
	bool exitCondition = false;
    
    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
        /*std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;*/
    
        std::cout << std::endl;
        std::cout << "INFORMACION: " << std::endl;
        
        int stockToCompare = presenter->GetShop()->GetStockFromItem(presenter->GetShop()->GetDummy()->GetItemInfo());
        
        std::cout << "EXISTE " << stockToCompare << " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA " << std::endl;
        std::cout << std::endl;
    
        std::cout << "Paso 5: Ingrese la cantidad de unidades a cotizar " << std::endl;
        std::cout << std::endl;

        std::cin >> option;

        checkQuantityInput(option, stockToCompare, exitCondition);
        
    } while (!exitCondition);
}

void View::checkResultOption(const std::string& option, bool& exitCondition)
{
    if (option == "3")
    {
        std::cout.flush();
        exitCondition = true;
    }
    else
    {
        std::cout << "Opcion ingresada incorrecta, intente nuevamente..." << std::endl;
        std::cin.get();
        exitCondition = false;
    }
}

void View::showResultMenu()
{
    std::string option;
	bool exitCondition = false;
    
    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
        
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        
        std::cout << "Numero de identificacion: " << presenter->GetShop()->GetQuoteId() << std::endl;
        std::cout << "Fecha y Hora de la cotizacion: " << presenter->GetShop()->GetTempQuote()->GetDate() << std::endl;
        std::cout << "Codigo del Vendedor: " << presenter->GetShop()->GetSeller()->GetCode() << std::endl;
        std::cout << "Prenda cotizada: " << presenter->GetShop()->GetItemInfo() << std::endl;
        std::cout << "Precio Unitario: " << presenter->GetShop()->GetDummy()->unitPrice << std::endl;
        std::cout << "Cantidad de unidades cotizadas: " << presenter->GetShop()->GetTempQuote()->quantity << std::endl;
        std::cout << "Precio Final: " << presenter->GetShop()->GetTempQuote()->CalculatePrice(presenter->GetShop()->GetDummy()) << std::endl;
    
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;

        std::cin >> option;
        
        checkResultOption(option, exitCondition);
        
    } while (!exitCondition);
}

void View::checkQuoteOption(const std::string& option, bool& exitCondition)
{
    if (option == "1")
    {
        std::system("cls");

        presenter->CreateTempQuote();
        presenter->CreateShirtDummy();
        
        showShirtSleeveMenu();
        showShirtNeckMenu();
        exitCondition = true;
    }
    else if (option == "2")
    {
        std::system("cls");
        
        presenter->CreateTempQuote();
        presenter->CreatePantDummy();
        
        showPantMenu();
        exitCondition = true;
    }
    else if (option == "3")
    {
        std::cout.flush();
        exitCondition = true;
    }
    else
    {
        std::cout << "Opcion ingresada incorrecta, intente nuevamente..." << std::endl;
        std::cin.get();
        exitCondition = false;
    }

    showQualityMenu();
    showUnitPriceMenu();
    showQuantityMenu();
    
    showResultMenu();
    
}

void View::showQuoteMenu()
{
    std::string option;
	bool exitCondition = false;
    
    do
    {
        std::system("cls");
        std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Presiona 3 para volver al menu principal" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Paso 1: Selecciona la prenda a cotizar: " << std::endl;
        std::cout << std::endl;
        std::cout << "1) Camisa " << std::endl;
        std::cout << "2) Pantalon " << std::endl;

        std::cin >> option;

        checkQuoteOption(option, exitCondition);
        
    } while (!exitCondition);

    showMainMenu();
}

void View::checkMainOption(std::string& option, bool& exitCondition)
{
    if (option == "1")
    {
        std::system("cls");
        showHistoryMenu();
		exitCondition = false;
    }
    else if (option == "2")
    {
        std::system("cls");
        showQuoteMenu();
		exitCondition = false;
    }
    else if (option == "3")
    {
        std::cout.flush();
        exit(EXIT_SUCCESS);
    }
    else
    {
        std::cout << "Opcion ingresada incorrecta, intente nuevamente..." << std::endl;
		std::cin.get();
		exitCondition = false;
    }
}
