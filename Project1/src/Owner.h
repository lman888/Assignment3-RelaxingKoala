#pragma once
#include "IObserver.h"
#include "Statistics.h"
#include <iostream>
#include <string>
using namespace std;

class Owner : public IObserver {
public:
    void Update(const string& message_from_subject) override;
};
