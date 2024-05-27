#pragma once
#include <vector>
#include <map> 
#include <string>
#include "Receipt.h"
using namespace std;


class Statistics
{
public:
	static Statistics& GetInstance()
	{
		static Statistics Instance;
		return Instance;
	}

	multimap<string, float> itemsOrdered;
	string deliveryType;
	float totalAmount;


	void WriteRecord(Receipt* aReceipt);

	void RetrieveRecord();

<<<<<<< HEAD
	//string DisplayStatistics();

	//multimap<string, float> getItems() const;
	//string getDeliveryType() const;
	//float getTotal() const;
=======
	void DisplayStatistics();
>>>>>>> b30c640eee30351a3f9c06f47362fc8ca1f109b7

private:
	
	vector<Receipt> record;
};