#pragma once
#include <map>
#include <string>

class Order
{
public:

    Order();
    ~Order() = default;
    
    void AddToOrder(const std::string& aItem, float aItemCost);

    void RemoveFromOrder(const std::string& aItem);

    void ShowOrder() const;

    void ShowTotalCost() const;

    void GenerateReceipt() const;
    
private:
    std::map<std::string, float> OrderItems;

    float TotalCost;
};
