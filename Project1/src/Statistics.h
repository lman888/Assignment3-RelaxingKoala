#pragma once
#include <vector>
#include <map>
#include <memory>
#include <string>
#include <list>
#include "ISubject.h"
#include "Receipt.h"
using namespace std;

class Statistics : public ISubject
{
public:
	static Statistics &GetInstance()
	{
		static Statistics Instance;
		return Instance;
	}

	multimap<string, float> itemsOrdered;
	string deliveryType;
	float totalAmount;

	void WriteRecord(Receipt *aReceipt);

	void RetrieveRecord();

	void DisplayStatistics();

	//overriding the subject interface
	void Attach(IObserver* observer);
	void Detach(IObserver* observer);
	void Notify();

private:
	vector<Receipt> record;

	list<IObserver*> record_observer;
};