//
//  Staff.cpp
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 18/5/2024.
//

#include "Staff.h"
#include "DeliveryStaff.h"
#include "Waiter.h"
#include "KitchenStaff.h"

std::unique_ptr<Staff> Staff::createStaff(const std::string& type) {
    if (type == "Delivery") {
        return std::make_unique<DeliveryStaff>();
    } else if (type == "Waiter") {
        return std::make_unique<Waiter>();
    } else if (type == "Kitchen") {
        return std::make_unique<KitchenStaff>();  
    } else {
        throw std::runtime_error("Unsupported staff type!");
    }
}

//sample implementation
//auto staff1 = Staff::createStaff("Delivery");
//    auto staff2 = Staff::createStaff("Waiter");
//    auto staff3 = Staff::createStaff("Kitchen");
//
//    staff1->performTask();
//    staff2->performTask();
//    staff3->performTask();
