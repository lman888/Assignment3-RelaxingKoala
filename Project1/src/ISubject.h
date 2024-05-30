#pragma once
#include "IObserver.h"

class ISubject { //interface inherited by subjects that are allowed to be notified to Observers
public:
	virtual ~ISubject() {};
	virtual void AttachObserver(IObserver* observer) = 0;
	virtual void DetachObserver(IObserver* observer) = 0;
	virtual void NotifyObservers() = 0;
};
