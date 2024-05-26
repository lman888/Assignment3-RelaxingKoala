//
//  KitchenStaff.h
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 18/5/2024.
//

#ifndef KitchenStaff_h
#define KitchenStaff_h

#include "Staff.h"
#include "Order.h"

class KitchenStaff : public Staff
{
public:
    void performTask(Order &order) override; // Overridden performTask method
};

#endif /* KitchenStaff_h */
