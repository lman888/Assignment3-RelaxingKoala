#include "Order.h"
#include <iostream>
#include "Receipt.h"
#include <iomanip>

Order::Order()
{
    TotalCost = 0.0f;
}

void Order::AddToOrder(const std::string &aItem, float aItemCost)
{
    OrderItems.insert({aItem, aItemCost});
    TotalCost += ItemCost;
}

void Order::RemoveFromOrder(const std::string &aItem)
{
    if (OrderItems.empty())
    {
        std::cout << "Your Cart is currently Empty!\n";
        return;
    }

    for (std::pair<const std::string, float> &OrderItem : OrderItems)
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

    for (const std::pair<const std::string, float> &OrderItem : OrderItems)
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
    // TODO : extract the delivery type : Dine-in, Delivery or Takeaway
    // I print to test it.
    std::cout << "Receipt has been Generated!\n";
    Receipt receipt(TotalCost, OrderItems, "dine-in");
    std::cout << "Order finished. Receipt generated." << std::endl;

    std::cout << "Receipt data: " << std::endl;
    auto data = receipt.getData();

    // Convert timestamp to a string representing local time
    std::time_t timestamp = std::get<0>(data);
    std::cout << "Timestamp: " << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S") << std::endl;

    std::cout << "Items ordered: " << std::endl;
    for (const auto &item : std::get<1>(data))
    {
        std::cout << item.first << ": " << item.second << std::endl;
    }
    std::cout << "Delivery type: " << std::get<2>(data) << std::endl;
    std::cout << "Total amount: " << std::get<3>(data) << std::endl;
}