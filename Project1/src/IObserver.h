#pragma once
#include<string>
class IObserver { //interface inherited by observers, can change name to staff ig, cuz its the product?
public:
	virtual ~IObserver() {};
	virtual void Update(const std::string& message_from_subject) = 0;
};