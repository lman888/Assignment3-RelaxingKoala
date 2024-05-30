#ifndef KITCHEN_STAFF_H
#define KITCHEN_STAFF_H

#include "Staff.h"

class KitchenStaff : public Staff
{
public:
    KitchenStaff(Reservation &reservation);
    ~KitchenStaff();

    void performTask() override;
    void Update(const std::string &message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();

private:
    std::string message_from_subject_;
    Reservation &subject_;
    static int static_number_;
    int number_;
};

#endif // KITCHEN_STAFF_H
