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

	void DisplayStatistics();

private:
	
	vector<Receipt> record;
};