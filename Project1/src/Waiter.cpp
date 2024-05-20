//
//  Waiter.cpp
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 18/5/2024.
//

#include <stdio.h>
#include "Waiter.h"
#include <iostream>
#include <sstream>
#include <fstream>

Waiter::Waiter()
{
    std::cout << "Logged in as a waiter" << std::endl;
    promptUpdateMenu();
}

Waiter::~Waiter()
{
}

void Waiter::performTask()
{
    std::cout << "Serving customers at the restaurant." << std::endl;
}

void Waiter::promptUpdateMenu()
{
    std::cout << "Do you want to update the menu availability? (yes/no): ";
    std::string response;
    std::cin >> response;

    if (response == "yes")
    {
        std::map<std::string, float> itemsToUpdate;
        std::string itemName;
        float itemPrice;
        std::string action;

        std::cout << "Enter 'add' to add an item or 'delete' to remove an item: ";
        std::cin >> action;
        MenuAction menuAction;
        if (action == "add")
        {
            menuAction = MenuAction::Add;
            std::cout << "Enter item name and price: ";
            std::cin >> itemName >> itemPrice;
            itemsToUpdate[itemName] = itemPrice;
        }
        else if (action == "delete")
        {
            menuAction = MenuAction::Delete;
            std::cout << "Enter item name to delete: ";
            std::cin >> itemName;
            itemsToUpdate[itemName] = 0; // Price is irrelevant for delete
        }
        else
        {
            std::cout << "Invalid action specified. Exiting update process." << std::endl;
            return; // Exit the function if the action is not recognized
        }

        updateMenuAvailability(menuAction, itemsToUpdate);
    }
    else
    {
        std::cout << "No updates made to the menu." << std::endl;
    }
}

void Waiter::updateMenuAvailability(MenuAction action, const std::map<std::string, float> &items)
{
    // This method would be similar to the previous implementation
    // Add or delete items in MenuItems.txt based on user input
    std::map<std::string, float> currentMenu;
    std::ifstream fileIn("MenuItems.txt");
    std::string line;

    while (getline(fileIn, line))
    {
        std::istringstream iss(line);
        std::string name;
        float price;
        if (iss >> name >> price)
        {
            currentMenu[name] = price;
        }
    }
    fileIn.close();

    if (action == MenuAction::Add)
    {
        std::cout << "Adding new items to the menu:" << std::endl;
        for (const auto &item : items)
        {
            currentMenu[item.first] = item.second;
            std::cout << " - " << item.first << ": $" << item.second << std::endl;
        }
    }
    else if (action == MenuAction::Delete)
    {
        std::cout << "Removing items from the menu:" << std::endl;
        for (const auto &item : items)
        {
            if (currentMenu.find(item.first) != currentMenu.end())
            {
                currentMenu.erase(item.first);
                std::cout << " - " << item.first << std::endl;
            }
        }
    }

    // Write the updated menu back to the file
    std::ofstream fileOut("MenuItems.txt");
    for (const auto &item : currentMenu)
    {
        fileOut << item.first << " " << item.second << std::endl;
    }
    fileOut.close();
}

//    Waiter myWaiter;
