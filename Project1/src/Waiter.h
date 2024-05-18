//
//  Waiter.h
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 18/5/2024.
//

#ifndef Waiter_h
#define Waiter_h

#include "Staff.h"

class Waiter : public Staff {
public:
    void performTask() override; // Overridden performTask method
    void updateMenuAvailability(); // Additional method specific to Waiter
};



#endif /* Waiter_h */
