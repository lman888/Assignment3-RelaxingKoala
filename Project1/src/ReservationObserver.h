
class ReservationObserver : public IObserver
{
public:
    ReservationObserver(Reservation &subject) : subject_(subject)
    {
        this->subject_.AttachObserver(this);
        std::cout << "ReservationObserver \"" << ++ReservationObserver::static_number_ << "\" instantiated.\n";
        this->number_ = ReservationObserver::static_number_;
    }
    virtual ~ReservationObserver()
    {
        std::cout << "Goodbye from ReservationObserver \"" << this->number_ << "\".\n";
    }

    void Update(const std::string &message_from_subject) override
    {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList()
    {
        subject_.DetachObserver(this);
        std::cout << "ReservationObserver \"" << number_ << "\" removed from the reservation list.\n";
    }
    void PrintInfo()
    {
        std::cout << "Notification to ReservationObserver \"" << this->number_ << "\": " << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    Reservation &subject_;
    static int static_number_;
    int number_;
};
int ReservationObserver::static_number_ = 0;
