#include "Order.h"
#include <iostream>
#include "Receipt.h"
#include "Menu.h"
#include <iomanip>
using namespace std;

Order::Order(Menu *aMenu)
{
    MenuItems = aMenu;
    TotalCost = 0.0f;
}

void Order::AttachObserver(IObserver* observer) {
    list_observer_.push_back(observer);
    cout << "Observer observer added\n";
}
void Order::DetachObserver(IObserver* observer) {
    list_observer_.remove(observer);
    cout << "Observer observer removed\n";
}
void Order::NotifyObservers() {
    std::list<IObserver*>::iterator iterator = list_observer_.begin();
    this->HowManyObservers();
    while (iterator != list_observer_.end()) {
        (*iterator)->Update(message_);
        ++iterator;
    }
}
void Order::MessageToBeNotifiedToObservers(std::string message = "Empty") {
    this->message_ = message;
    this->NotifyObservers();
}
void Order::HowManyObservers() {
    std::cout << "There are " << list_observer_.size() << " observers observing the reservation list.\n";
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
            OrderItems.insert({ MenuItem.first, MenuItem.second});
            TotalCost += MenuItem.second;
            std::cout << "Successfully added Item: " << MenuItem.first << " to Order!\n";
            return;
        }
    }
    std::cout << "Please enter a valid Menu Item\n";
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
            std::cout << "Successfully removed Item: " << OrderItem.first << " from the order Order!\n";
            return;
        }
    }
    std::cout << "Please enter a valid Menu Item\n";
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

void Order::ClearOrder()
{
     TotalCost =0;
     //clear all items from orderitems here please
}

void Order::ShowTotalCost() const
{
    std::cout << "Total: " << TotalCost << "\n";
}

void Order::GenerateReceipt() const
{
    std::cout << "Checkout requested, generating receipt." << std::endl;
    Receipt receipt(TotalCost, OrderItems, "Dine-in");
    std::cout << "Receipt has been generated!\n";
}

bool Order::CaseSensitiveStringCompare(const std::string &aItem, const std::string &aMenuItem)
{
    if (aItem.length() != aMenuItem.length())
    {
        //moved to AddToOrder and RemoveFromOrder functions cuz its looping
        //std::cout << "Please enter a valid Menu Item\n";
        
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