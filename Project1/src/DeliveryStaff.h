//
//  DeliveryStaff.h
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 18/5/2024.
//

#ifndef DeliveryStaff_h
#define DeliveryStaff_h

#include "Staff.h"

class DeliveryStaff : public Staff {
public:
    void performTask() override; // Overridden performTask method
};



#endif /* DeliveryStaff_h */
