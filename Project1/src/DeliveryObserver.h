#pragma once
#include <iostream>
#include <string>
#include "IObserver.h" // Include the base interface
#include "Order.h"

class DeliveryObserver : public IObserver
{
public:
    // Constructor and destructor
    DeliveryObserver::DeliveryObserver(Order &subject) : subject_(subject)
    {
        this->subject_.AttachObserver(this);
        this->number_ = ++DeliveryObserver::static_number_;
        std::cout << "DeliveryObserver \"" << this->number_ << "\" instantiated.\n";
    }
    virtual ~DeliveryObserver();

    // Overriding the Update method from IObserver
    void Update(const std::string &message_from_subject) override;

    // Additional methods specific to the observer
    void RemoveMeFromTheList();
    void PrintInfo() const;

private:
    std::string message_from_subject_;
    Order &subject_;
    static int static_number_;
    int number_;
};

int DeliveryObserver::static_number_ = 0; // Initialize static member

DeliveryObserver::DeliveryObserver(Order &subject) : subject_(subject)
{
    this->subject_.AttachObserver(this);
    this->number_ = ++DeliveryObserver::static_number_;
    std::cout << "DeliveryObserver \"" << this->number_ << "\" instantiated.\n";
}

DeliveryObserver::~DeliveryObserver()
{
    std::cout << "Goodbye from DeliveryObserver \"" << this->number_ << "\".\n";
}

void DeliveryObserver::Update(const std::string &message_from_subject)
{
    this->message_from_subject_ = message_from_subject;
    PrintInfo();
}

void DeliveryObserver::RemoveMeFromTheList()
{
    subject_.DetachObserver(this);
    std::cout << "DeliveryObserver \"" << number_ << "\" removed from the delivery list.\n";
}

void DeliveryObserver::PrintInfo() const
{
    std::cout << "Notification to DeliveryObserver \"" << this->number_ << "\": " << this->message_from_subject_ << "\n";
}
