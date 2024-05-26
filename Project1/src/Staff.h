//
//  Staff.h
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 18/5/2024.
//

#ifndef Staff_h
#define Staff_h

#include <memory>
#include <string>
#include "Order.h"

class Staff
{
public:
    virtual void performTask(Order &order) = 0; //  virtual function for performing role-specific tasks
    virtual ~Staff() {}                         //  destructor

    // Factory Method:  create specific staff objects
    static std::unique_ptr<Staff> createStaff(const std::string &type);
};

#endif
