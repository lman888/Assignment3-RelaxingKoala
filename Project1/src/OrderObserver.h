#include<iostream>
class OrderObserver : public IObserver {
public:
    OrderObserver(Order& subject) : subject_2(subject) {
        this->subject_2.AttachObserver(this);
        std::cout << "OrderObserver \"" << ++OrderObserver::static_number_ << "\" instantiated.\n";
        this->number_ = OrderObserver::static_number_;
    }
    virtual ~OrderObserver() {
        std::cout << "Goodbye from OrderObserver \"" << this->number_ << "\".\n";
    }

    void Update(const std::string& message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList() {
        subject_2.DetachObserver(this);
        std::cout << "OrderObserver \"" << number_ << "\" removed from the order list.\n";
    }
    void PrintInfo() {
        std::cout << "Notification to OrderObserver \"" << this->number_ << "\": " << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    Order& subject_2;
    static int static_number_;
    int number_;
};
int OrderObserver::static_number_ = 0;

