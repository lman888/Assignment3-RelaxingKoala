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
#include <memory>

class Receipt
{
private:
    char* timestamp;
    std::multimap<std::string, float> itemsOrdered;
    std::string deliveryType;
    float totalAmount;

    void DisplayReceiptData();
    
public:
    // Constructor
    Receipt(float totalAmount, const std::multimap<std::string, float> &itemsOrdered, const std::string &deliveryType);

    // Getter for all fields
    //std::tuple<std::time_t, std::multimap<std::string, float>, std::string, float>* getData() const;
    std::unique_ptr<std::tuple<char*, std::multimap<std::string, float>, std::string, float>> getData();
};

#endif // RECEIPT_H
