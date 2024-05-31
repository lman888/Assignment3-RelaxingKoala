#include "KitchenStaff.h"
#include <iostream>

int KitchenStaff::static_number_ = 0;

KitchenStaff::KitchenStaff(Reservation &reservation) : subject_(reservation)
{
    subject_.AttachObserver(this);
    std::cout << "IObserver inherited KitchenStaff num \"" << ++KitchenStaff::static_number_ << "\" instantiated.\n";
    this->number_ = KitchenStaff::static_number_;
}

KitchenStaff::~KitchenStaff()
{
    subject_.DetachObserver(this);
    std::cout << "Goodbye from KitchenStaff num \"" << this->number_ << "\".\n";
}

void KitchenStaff::performTask()
{
    std::cout << "Kitchen staff is processing the order." << std::endl;
    // Implementation of kitchen task
}

void KitchenStaff::Update(const std::string &message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void KitchenStaff::RemoveMeFromTheList()
{
    subject_.DetachObserver(this);
    std::cout << "KitchenStaff num \"" << number_ << "\" removed from the list.\n";
}

void KitchenStaff::PrintInfo()
{
    std::cout << "Notification to: KitchenStaff num\"" << this->number_ << "\": " << this->message_from_subject_ << "\n";
}
