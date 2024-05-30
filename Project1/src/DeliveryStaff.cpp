#include "DeliveryStaff.h"
#include <iostream>

int DeliveryStaff::static_number_ = 0;

DeliveryStaff::DeliveryStaff(Reservation &reservation) : subject_(reservation)
{
    subject_.Attach(this);
    std::cout << "IObserver inherited DeliveryStaff num \"" << ++DeliveryStaff::static_number_ << "\" instantiated.\n";
    this->number_ = DeliveryStaff::static_number_;
}

DeliveryStaff::~DeliveryStaff()
{
    subject_.Detach(this);
    std::cout << "Goodbye from DeliveryStaff num \"" << this->number_ << "\".\n";
}

void DeliveryStaff::performTask()
{
    std::cout << "Delivery staff is processing the order." << std::endl;
    // Implementation of delivery task
}

void DeliveryStaff::Update(const std::string &message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void DeliveryStaff::RemoveMeFromTheList()
{
    subject_.Detach(this);
    std::cout << "DeliveryStaff num \"" << number_ << "\" removed from the list.\n";
}

void DeliveryStaff::PrintInfo()
{
    std::cout << "Notification to: DeliveryStaff num\"" << this->number_ << "\": " << this->message_from_subject_ << "\n";
}
