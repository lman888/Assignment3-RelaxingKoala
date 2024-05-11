//
//  Receipt.h
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 11/5/2024.
//

#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>
#include <map>
#include <ctime>

class Receipt
{
private:
    std::time_t timestamp;
    std::map<std::string, float> itemsOrdered;
    std::string deliveryType;
    float totalAmount;

public:
    // Constructor
    Receipt(float totalAmount, const std::map<std::string, float> &itemsOrdered, const std::string &deliveryType);

    // Getter for all fields
    std::tuple<std::time_t, std::map<std::string, float>, std::string, float> getData() const;
};

#endif // RECEIPT_H
