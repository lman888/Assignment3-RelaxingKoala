#ifndef DELIVERY_STAFF_H
#define DELIVERY_STAFF_H

#include "Staff.h"

class DeliveryStaff : public Staff
{
public:
    DeliveryStaff(Reservation &reservation);
    ~DeliveryStaff();

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

#endif // DELIVERY_STAFF_H
