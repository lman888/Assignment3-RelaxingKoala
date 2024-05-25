//
//  Receipt.cpp
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 11/5/2024.
//

#include "Receipt.h"

#include <iomanip>
#include <stdio.h>
#include <iostream>

Receipt::Receipt(float totalAmount, const std::multimap<std::string, float> &itemsOrdered, const std::string &deliveryType) : totalAmount(totalAmount), itemsOrdered(itemsOrdered), deliveryType(deliveryType)
{
    std::time_t currentTime = std::time(nullptr);
    timestamp = currentTime;
}

std::tuple<std::time_t, std::multimap<std::string, float>, std::string, float> Receipt::getData() const
{
    return std::make_tuple(timestamp, itemsOrdered, deliveryType, totalAmount);
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