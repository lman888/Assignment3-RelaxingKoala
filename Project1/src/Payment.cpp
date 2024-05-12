//
//  Payment.cpp
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 10/5/2024.
//

#include <stdio.h>
#include "payment.h"

Payment::Payment() {}

void Payment::initiatePayment() {
    // Ask user for credit card number
    std::cout << "Please enter your credit card number: ";
    std::cin >> creditCardNumber;

    // Validate credit card number length
    while (creditCardNumber.length() != 10) {
        std::cout << "Invalid credit card number. It should be 10 digits long." << std::endl;
        std::cout << "Please enter your credit card number again: ";
        std::cin >> creditCardNumber;
    }

    // Payment successful if credit card number is 10 digits
    std::cout << "Payment Successful!" << std::endl;
}
