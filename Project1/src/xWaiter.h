
class xWaiter : public IObserver {
public:
    xWaiter(Reservation& subject) : subject_(subject) {
        this->subject_.Attach(this);
        std::cout << "xWaiter num \"" << ++xWaiter::static_number_ << "\"instantiated.\n";
        this->number_ = xWaiter::static_number_;
    }
    virtual ~xWaiter() {
        std::cout << "Goodbye from xWaiter num\"" << this->number_ << "\".\n";
    }

    void Update(const std::string& message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList() {
        subject_.Detach(this);
        std::cout << "xWaiter num\"" << number_ << "\" removed from the list.\n";
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



///
/*
class Observer : public IObserver {
public:
    Observer(Subject& subject) : subject_(subject) {
        this->subject_.Attach(this);
        std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
        this->number_ = Observer::static_number_;
    }
    virtual ~Observer() {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Update(const std::string& message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList() {
        subject_.Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo() {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    Subject& subject_;
    static int static_number_;
    int number_;
};

int Observer::static_number_ = 0;
*/