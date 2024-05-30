#include<iostream>
class xKitchen : public IObserver {
public:
    xKitchen(Order& subject) : subject_2(subject) {
        this->subject_2.AttachObserver(this);
        std::cout << "IObserver inherited xKitchen num \"" << ++xKitchen::static_number_ << "\" instantiated.\n";
        this->number_ = xKitchen::static_number_;
    }
    virtual ~xKitchen() {
        std::cout << "Goodbye from xKitchen num \"" << this->number_ << "\".\n";
    }

    void Update(const std::string& message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList() {
        subject_2.DetachObserver(this);
        std::cout << "xKitchen num \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo() {
        std::cout << "Notification to: xKitchen num\"" << this->number_ << "\": " << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    Order& subject_2;
    static int static_number_;
    int number_;
};
int xKitchen::static_number_ = 0;

