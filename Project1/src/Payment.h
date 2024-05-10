#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>

class Payment {
private:
    std::string creditCardNumber;

public:
    Payment();
    void initiatePayment();
};

#endif /* PAYMENT_H */

