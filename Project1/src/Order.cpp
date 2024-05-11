#include "Order.h"
#include <iostream>

Order::Order()
{
    TotalCost = 0.0f;
}

void Order::AddToOrder(const std::string& aItem, float aItemCost)
{
    OrderItems.insert({aItem, aItemCost});
    TotalCost += ItemCost;
}

void Order::RemoveFromOrder(const std::string& aItem)
{
    if (OrderItems.empty())
    {
        std::cout << "Your Cart is currently Empty!\n";
        return;
    }
    
    for (std::pair<const std::string, float>& OrderItem : OrderItems)
    {
        if (OrderItem.first == aItem)
        {
            TotalCost -= OrderItem.second;
            OrderItems.erase(OrderItem.first);
            return;
        }
    }
}

void Order::ShowOrder() const
{
    if (OrderItems.empty())
    {
        std::cout << "Your Cart is currently Empty!\n";
        return;
    }
    
    for (const std::pair<const std::string, float>& OrderItem : OrderItems)
    {
        std::cout << "Order Item: " << OrderItem.first << " Cost: " << OrderItem.second << std::endl;
    }
}

void Order::ShowTotalCost() const
{
    std::cout << "Total: " << TotalCost << "\n";
}

void Order::GenerateReceipt() const
{
    std::cout << "Receipt has been Generated!\n";
}