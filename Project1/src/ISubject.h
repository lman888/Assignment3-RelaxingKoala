#pragma once
#include "IObserver.h"

class ISubject { //interface inherited by subjects that are allowed to be notified to Observers
public:
	virtual ~ISubject() {};
	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
	virtual void Notify() = 0;
};
