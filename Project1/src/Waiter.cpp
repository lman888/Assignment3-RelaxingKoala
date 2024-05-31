#include "Waiter.h"
#include <iostream>

int Waiter::static_number_ = 0;

Waiter::Waiter(Reservation &reservation) : subject_(reservation)
{
    subject_.AttachObserver(this);
    std::cout << "IObserver inherited Waiter num \"" << ++Waiter::static_number_ << "\" instantiated.\n";
    this->number_ = Waiter::static_number_;
}

Waiter::~Waiter()
{
    subject_.DetachObserver(this);
    std::cout << "Goodbye from Waiter num \"" << this->number_ << "\".\n";
}

void Waiter::performTask()
{
    std::cout << "Waiter is processing the order." << std::endl;
    // Implementation of waiter's task
}

void Waiter::Update(const std::string &message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void Waiter::RemoveMeFromTheList()
{
    subject_.DetachObserver(this);
    std::cout << "Waiter num \"" << number_ << "\" removed from the list.\n";
}

void Waiter::PrintInfo()
{
    std::cout << "Notification to: Waiter num\"" << this->number_ << "\": " << this->message_from_subject_ << "\n";
}
