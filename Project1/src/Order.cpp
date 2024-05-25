#include "Order.h"
#include <iostream>
#include "Receipt.h"
#include "Menu.h"
#include <iomanip>

Order::Order(Menu *aMenu)
{
    MenuItems = aMenu;
    TotalCost = 0.0f;
}

void Order::AddToOrder(const std::string &aItem)
{
    if (!MenuItems)
    {
        std::cout << "Menu is not valid\n";
        return;
    }

    for (std::pair<const std::string, float> &MenuItem : MenuItems->GetMenuItems())
    {
        if (CaseSensitiveStringCompare(aItem, MenuItem.first))
        {
            OrderItems.insert({aItem, MenuItem.second});
            TotalCost += MenuItem.second;
            std::cout << "Successfully added Item: " << aItem << " to Order!\n";
            break;
        }
    }
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
        if (CaseSensitiveStringCompare(aItem, OrderItem.first))
        {
            TotalCost -= OrderItem.second;
            OrderItems.erase(OrderItem.first);
            std::cout << "Successfully removed Item: " << aItem << " from the order Order!\n";
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
    std::cout << "Receipt has been Generated!\n";
    Receipt receipt(TotalCost, OrderItems, "dine-in");
    std::cout << "Order finished. Receipt generated." << std::endl;

    std::cout << "Receipt data: " << std::endl;
    auto data = receipt.getData();

    // Retrieve the timestamp from the receipt data
    std::time_t timestamp = std::get<0>(data);

    // Declare a tm struct to hold the local time
    struct tm localTime;

    // Convert the time_t timestamp to local time using localtime_r
    //localtime_r(&timestamp, &localTime); // Correct usage of localtime_r

    // Format and output the timestamp using std::put_time
    // std::put_time takes a pointer to a tm struct and a format string
    std::cout << "Timestamp: ";
    //std::cout << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << std::endl;

    std::cout << "Items ordered: " << std::endl;
    for (const auto &item : std::get<1>(data))
    {
        std::cout << item.first << ": " << item.second << std::endl;
    }
    std::cout << "Delivery type: " << std::get<2>(data) << std::endl;
    std::cout << "Total amount: " << std::get<3>(data) << std::endl;
}

bool Order::CaseSensitiveStringCompare(const std::string &aItem, const std::string &aMenuItem)
{
    if (aItem.length() != aMenuItem.length())
    {
        std::cout << "Please enter a valid Menu Item\n";
        return false;
    }

    for (size_t i = 0; i < aItem.length(); i++)
    {
        if (std::tolower(aItem[i]) != std::tolower(aMenuItem[i]))
        {
            return false;
        }
    }
    return true;
}