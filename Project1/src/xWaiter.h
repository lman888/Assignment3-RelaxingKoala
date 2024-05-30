
class xWaiter : public IObserver {
public:
    xWaiter(Reservation& subject) : subject_(subject) {
        this->subject_.AttachObserver(this);
        std::cout << "IObserver inherited xWaiter num \"" << ++xWaiter::static_number_ << "\" instantiated.\n";
        this->number_ = xWaiter::static_number_;
    }
    virtual ~xWaiter() {
        std::cout << "Goodbye from xWaiter num \"" << this->number_ << "\".\n";
    }

    void Update(const std::string& message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList() {
        subject_.DetachObserver(this);
        std::cout << "xWaiter num \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo() {
        std::cout << "Notification to: xWaiter num\"" << this->number_ << "\": " << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    Reservation& subject_;
    static int static_number_;
    int number_;
};
int xWaiter::static_number_ = 0;
