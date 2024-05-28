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
    std::cout << "Order finished. Receipt generated." << std::endl;
    Receipt receipt(TotalCost, OrderItems, "dine-in");
    std::cout << "Receipt has been Generated!\n";
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