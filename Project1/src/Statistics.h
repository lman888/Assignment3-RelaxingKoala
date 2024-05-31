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


	void GetStatisticsFromSummaryFile();

	void DisplayBasicStatistics();

	void UpdateStatisticsFile(Receipt* aReceipt, float totalAmount);

	void WriteRecord(Receipt *aReceipt);

	void RetrieveRecord();

	void DisplayPastPurchases();

	//overriding the subject interface
	void AttachObserver(IObserver* observer);
	void DetachObserver(IObserver* observer);
	void NotifyObservers();

private:
	int numberOfDineIns;
	int numberOfDeliveries;
	int numberOfTakeaways;
	float totalEarned;
	string mostPopularMenuItem="";
	map<string, int> ItemsAndQuantityOrdered;

	vector<string> itemNameVector;

	list<IObserver*> record_observer;
};