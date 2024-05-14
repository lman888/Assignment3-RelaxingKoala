#pragma once
#include <map>
#include <string>

//Forward Declaration
class Menu;

class Order
{
public:

    Order(Menu* aMenu);
    ~Order() = default;
    
    void AddToOrder(const std::string& aItem);

    void RemoveFromOrder(const std::string& aItem);

    void ShowOrder() const;

    void ShowTotalCost() const;

    void GenerateReceipt() const;
    
private:

    bool CaseSensitiveStringCompare(const std::string& aItem, const std::string& aMenuItem);
    
    std::multimap<std::string, float> OrderItems;

    float TotalCost;

    Menu* MenuItems;
};
