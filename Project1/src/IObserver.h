#pragma once
class IObserver { //interface inherited by observers
public:
	virtual ~IObserver() {};
	virtual void Update(const std::string& message_from_subject) = 0;
};