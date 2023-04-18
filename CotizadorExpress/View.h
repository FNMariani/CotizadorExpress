#pragma once
#include <string>

#include "IView.h"
#include "Presenter.h"

class View : public IView
{
private:
    Presenter* presenter;
    void showMainMenu();
    
public:
    View();
    ~View() override;
    
    void checkHistoryOption(const std::string& option, bool& exitCondition);
    void showHistoryMenu();
    void checkSleeveOption(const std::string& option, bool& exitCondition);
    void showShirtSleeveMenu();
    void checkNeckOption(const std::string& option, bool& exitCondition);
    void showShirtNeckMenu();
    void checkPantOption(const std::string& option, bool& exitCondition);
    void showPantMenu();
    void checkQualityOption(const std::string& option, bool& exitCondition);
    void showQualityMenu();
    void showUnitPriceMenu();
    void showQuantityMenu();
    void checkResultOption(const std::string& option, bool& exitCondition);
    void showResultMenu();
    void checkQuoteOption(const std::string& option, bool& exitCondition);
    void showQuoteMenu();
    void checkMainOption(std::string& option, bool& exitCondition);
};
