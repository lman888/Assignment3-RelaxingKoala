#pragma once
#include <vector>
#include <map> 
#include <string>
#include "Receipt.h"
using namespace std;


class Statistics
{
public:
	Statistics();
	~Statistics() = default;

	multimap<string, float> itemsOrdered;
	string deliveryType;
	float totalAmount;


	void WriteRecord();

	void RetrieveRecord();

	//string DisplayStatistics();

	//multimap<string, float> getItems() const;
	//string getDeliveryType() const;
	//float getTotal() const;

private:
	
	vector<Receipt> record;
};

