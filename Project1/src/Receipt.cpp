//
//  Receipt.cpp
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 11/5/2024.
//

#include <stdio.h>
#include "Receipt.h"
#include "Receipt.h"

#include <chrono>
#include <iomanip>
#include <iostream>

#include "Statistics.h"

void Receipt::DisplayReceiptData()
{
    std::cout << "Receipt data: " << std::endl;

    std::cout << "Time Ordered: " << timestamp;
    std::cout << "Items ordered: " << std::endl;
    for (const pair<const string, float> &item : itemsOrdered)
    {
        std::cout << item.first << ": " << item.second << std::endl;
    }
    std::cout << "Delivery type: " << deliveryType << std::endl;
    std::cout << "Total amount: " << totalAmount << std::endl;
}

Receipt::Receipt(float totalAmount, const std::multimap<std::string, float> &itemsOrdered, const std::string &deliveryType) : totalAmount(totalAmount), itemsOrdered(itemsOrdered), deliveryType(deliveryType)
{
    // Get the current time as a time_point
    chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    // Convert the time_point to a time_t, which represents the time in seconds since the epoch
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert the time_t to a tm structure for local time in a thread-safe manner
    std::tm localTime;
    localtime_s(&localTime, &currentTime);

    // Create a buffer to store the formatted time string
    char timeString[26]; // asctime_s requires a buffer of at least 26 characters

    // Convert the tm structure to a human-readable string in a thread-safe manner
    asctime_s(timeString, sizeof(timeString), &localTime);

    timestamp = timeString;

    Statistics &statistics = Statistics::GetInstance();

    statistics.WriteRecord(this);

    DisplayReceiptData();
}

std::unique_ptr<std::tuple<char *, std::multimap<std::string, float>, std::string, float>> Receipt::getData()
{
    return std::make_unique<std::tuple<char *, std::multimap<std::string, float>, std::string, float>>(timestamp, itemsOrdered, deliveryType, totalAmount);
}

// calling Receipt class example
// Receipt receipt(TotalCost, OrderItems, "dine-in");
// std::cout << "Order finished. Receipt generated." << std::endl;
//
// std::cout << "Receipt data: " << std::endl;
// auto data = receipt.getData();
//
//// Convert timestamp to a string representing local time
// std::time_t timestamp = std::get<0>(data);
// std::cout << "Timestamp: " << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S") << std::endl;
//
// std::cout << "Items ordered: " << std::endl;
// for (const auto& item : std::get<1>(data)) {
//     std::cout << item.first << ": " << item.second << std::endl;
// }
// std::cout << "Delivery type: " << std::get<2>(data) << std::endl;
// std::cout << "Total amount: " << std::get<3>(data) << std::endl;
