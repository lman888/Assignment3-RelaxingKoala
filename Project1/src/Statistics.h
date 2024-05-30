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
	/*Statistics();
	~Statistics() = default;*/

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
	void AttachObserver(IObserver* observer) override 
	{
		record_observer.push_back(observer);
	}

	void DetachObserver(IObserver* observer) override
	{
		record_observer.erase(remove(record_observer.begin(), record_observer.end(), observer), record_observer.end());
	}
	void NotifyObservers();

private:
	//vector<Receipt> record;

	list<IObserver*> record_observer;
};