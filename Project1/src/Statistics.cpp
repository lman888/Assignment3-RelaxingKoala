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
	//WriteRecord();
}

void Statistics::RetrieveRecord()
{
	ifstream StatisticsFile("StatisticsDatabase/PurchaseRecords.txt");

	

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
	string deliveryType = "dine-in";
	float total = 14;

	//add a dummy record to the vector
	record.push_back(Receipt(total,items,deliveryType));

	
	if (StatisticsFile.is_open())
	{
		//iterate vector and get values to a tuple
		for (auto& receipt:record)
		{
			auto data = receipt.getData();
			multimap< string, float> itemsPurchased;
			time_t timeOfPurchase;
			string deliveryType;
			float total;

			//unpack the tuple
			tie(timeOfPurchase,itemsPurchased,deliveryType,total) = data;

			//write data to file
			StatisticsFile << timeOfPurchase << ","<< deliveryType << "," << total << "\n";
		}
		StatisticsFile.close();
	}
	else
	{
		cout << "Error to opening file";
		return;
	}
}

string Statistics::DisplayStatistics()
{
	
}


