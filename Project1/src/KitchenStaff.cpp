
#include "KitchenStaff.h"
#include <iostream>
#include <stdio.h>
#include "Order.h" // Assuming this is the header file where the Order class is defined

void KitchenStaff::performTask(Order &order)
{
    std::cout << "Preparing meals in the kitchen." << std::endl;
    // try
    // {
    //     std::cout << "Starting to prepare order.\n";
    //     order.updateStatus("Preparing");

    //     // Simulate the task of preparing the meal
    //     // This could be a sleep or just a placeholder for actual preparation logic
    //     std::this_thread::sleep_for(std::chrono::seconds(5)); // Simulating the preparation time

    //     order.updateStatus("Completed");
    //     std::odut << "Order preparation completed.\n";
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Error encountered during order preparation: " << e.what() << '\n';
    // }
}
