#include "Statistics.h"
#include <iostream>
#include <sstream>
#include "Receipt.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void Statistics::RetrieveRecord()
{
	ifstream StatisticsFile("StatisticsDatabase/PurchaseRecords.txt");
	
	if (StatisticsFile.is_open())
	{
		string line;
	}
}

void Statistics::WriteRecord(Receipt* aReceipt)
{
	ofstream StatisticsFile("StatisticsDatabase/PurchaseRecords.txt", ios::app);

	if (StatisticsFile.is_open())
	{
		unique_ptr<tuple<char*, multimap<string, float>, string, float>> ReceiptDataPtr = aReceipt->getData();
		const auto ReceiptData = *ReceiptDataPtr;
		
		for (const pair<const string, float> &item : std::get<1>(ReceiptData))
		{
			StatisticsFile << "Item: " << item.first << ": " << "Cost: "<< item.second << std::endl;
		}
		StatisticsFile << "Time: " << std::get<0>(ReceiptData) << "Order Type: " << std::get<2>(ReceiptData);
		StatisticsFile.close();
		NotifyObservers();
	}
	else
	{
		std::cout << "File could not be open";
	}
}

void Statistics::DisplayStatistics()
{
	//Look through a document and grab the variables and pass the two variables into an array

	std::ifstream StatsFile("StatisticsDatabase/PurchaseRecords.txt");

	if (StatsFile.is_open())
	{
		std::string Line;
        
		while (std::getline(StatsFile, Line))
		{
			std::cout << Line << std::endl;
		}

		StatsFile.close();
	}
	else
	{
		std::cerr << "Unable to open file!" << std::endl;
	}
}

void Statistics::NotifyObservers()
{
	for (IObserver* observer : record_observer)
	{
		observer->Update("Statistics updated");
	}
}