#include "Statistics.h"
#include <iostream>
#include <sstream>
#include "Receipt.h"
#include <fstream>
#include <iostream>
#include <iomanip> 
using namespace std;


Statistics::Statistics()
{
	
}

void Statistics::RetrieveRecord()
{
	ifstream StatisticsFile("StatisticsDatabase/PurchaseRecords.txt");

	multimap<string, float> itemsOrdered;
	string deliveryType;
	float totalAmount;

	if (StatisticsFile.is_open())
	{
		string line;
		while (getline(StatisticsFile,line))
		{
			istringstream StringStream(line);

			cout << line << endl;
		}
	}
}

void Statistics::WriteRecord()
{
	ofstream StatisticsFile("StatisticsDatabase/PurchaseRecords.txt");
	multimap< string, float> items = { {"Apple", 1.0}, {"Banana", 0.5} };
	time_t now = time(nullptr);
	

	if (StatisticsFile.is_open())
	{
		
		for (auto&Receipt:record)
		{
			//auto[itemsOrdered, deliveryType, totalAmount] = Receipt.getData();
		}
	}
}


