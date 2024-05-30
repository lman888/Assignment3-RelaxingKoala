#ifndef WAITER_H
#define WAITER_H

#include "Staff.h"

class Waiter : public Staff
{
public:
    Waiter(Reservation &reservation);
    ~Waiter();

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

#endif // WAITER_H
