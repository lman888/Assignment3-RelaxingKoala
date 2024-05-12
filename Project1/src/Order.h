#pragma once
#include <map>
#include <string>

class Order
{
public:

    Order();
    ~Order() = default;
    
    void AddToOrder(const std::string& Item, float ItemCost);

    void RemoveFromOrder(const std::string& Item);

    void ShowOrder() const;

    void ShowTotalCost() const;

    void GenerateReceipt() const;
    
private:
    std::map<std::string, float> OrderItems;

    float TotalCost;
};
