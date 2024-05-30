#ifndef STAFF_H
#define STAFF_H

#include <memory>
#include <string>
#include <iostream>
#include "IObserver.h"
#include "Reservation.h"
#include "Order.h"

class Staff : public IObserver
{
public:
    virtual void performTask() = 0; // Virtual function for performing role-specific tasks
    virtual ~Staff() {}             // Destructor

    // Factory Method: Create specific staff objects
    static std::unique_ptr<Staff> createStaff(const std::string &type, Reservation &reservation);
};

#endif // STAFF_H
