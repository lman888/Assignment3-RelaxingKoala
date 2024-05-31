#include "Statistics.h"
#include <iostream>
#include <sstream>
#include "Receipt.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Statistics::RetrieveRecord()
{
	ifstream StatisticsFile("StatisticsDatabase/PurchaseRecords.txt");
	
	if (StatisticsFile.is_open())
	{
		string line;
	}
}
void Statistics::GetStatisticsFromSummaryFile(){
	std::ifstream StatsFile("StatisticsDatabase/StatisticsSummary.txt");
	string Line;
	string item;
	int quantity = 0;
	int found = 0;

	if (StatsFile.is_open())
	{
		//StringStream >> numberOfDineIns >> numberOfDeliveries >> numberOfTakeaways >> totalEarned;
		
		/*numberOfDineIns = 2; 
		numberOfTakeaways = 3;
		numberOfDeliveries = 4;
		totalEarned = 5;
		ItemsAndQuantityOrdered["Apple"] = 2;
		itemNameVector.push_back("Apple");
		ItemsAndQuantityOrdered["Banana"] = 4;
		itemNameVector.push_back("Banana");*/
		while (std::getline(StatsFile, Line)) {
			istringstream StringStream(Line);

			if (StringStream >> numberOfDineIns >> numberOfTakeaways >> numberOfDeliveries >> totalEarned) {
				while (std::getline(StatsFile, Line)) {
					istringstream StringStream(Line);
					if (StringStream >> item >> quantity)
					{

						ItemsAndQuantityOrdered[item] = quantity;
						for (int i = 0; i < itemNameVector.size(); i++) {
							if (item == itemNameVector[i]) {
								found = 1;
							}
						}
						if (found == 0) {
							itemNameVector.push_back(item);
						}
						cout << quantity << " of " << item << "(s) have been sold in total." << endl;

					}
					else
					{
						cout << "Error Parsing Following Line " << Line << endl;
					}
				}

				cout << "numberOfDineIns: " << numberOfDineIns << endl;
				cout << "numberOfDeliveries: " << numberOfDeliveries << endl;
				cout << "numberOfTakeaways: " << numberOfTakeaways << endl;
				cout << "totalEarned: " << totalEarned << endl;
			}
			else
			{
				cout << "Error Parsing First Line " << Line << endl;
			}
		}
			
		StatsFile.close();
	}
	else
	{
		std::cerr << "Unable to open file!" << std::endl;
	}
}

void Statistics::UpdateStatisticsFile(Receipt* aReceipt, float totalAmount) {
	int found = 0;
	ofstream StatisticsFile("StatisticsDatabase/StatisticsSummary.txt");//, ios::app

	unique_ptr<tuple<char*, multimap<string, float>, string, float>> ReceiptDataPtr = aReceipt->getData();
	const auto ReceiptData = *ReceiptDataPtr;

	if (std::get<2>(ReceiptData) == "Dine-in") {
		numberOfDineIns += 1;
	}else if (std::get<2>(ReceiptData) == "Takeaway") {
		numberOfTakeaways += 1;
	}else if (std::get<2>(ReceiptData) == "Delivery") {
		numberOfDeliveries += 1;
	}
	totalEarned += totalAmount;

	
	for (const pair<const string, float>& item : std::get<1>(ReceiptData))
	{
		//cout << "Name of item checkuing for vector"<<item.first;
		ItemsAndQuantityOrdered[item.first] += 1;
		for (int i = 0; i < itemNameVector.size(); i++) {
			if (item.first == itemNameVector[i]){
				found = 1;
			}
		}
		if (found == 0) {
			itemNameVector.push_back(item.first);
		}
	}

	if (StatisticsFile.is_open()) {
		StatisticsFile << numberOfDineIns << " " << numberOfTakeaways << " " << numberOfDeliveries << " " << totalEarned << "\n";

		for (int i = 0; i < itemNameVector.size(); i++) {
			//cout << "itemNameVector[i]" << itemNameVector[i];
			StatisticsFile << itemNameVector[i] << " " << ItemsAndQuantityOrdered[itemNameVector[i]] << "\n";
		}
		StatisticsFile.close();
	}
		/*}
		else {
			ItemsAndQuantityOrdered[item.first] += 1;
		}*/
		
	

	

	/*if (StatisticsFile.is_open())
	{
	}*/
}

void Statistics::WriteRecord(Receipt* aReceipt)
{
	ofstream StatisticsFile("StatisticsDatabase/PurchaseRecords.txt", ios::app);

	if (StatisticsFile.is_open())
	{

		unique_ptr<tuple<char*, multimap<string, float>, string, float>> ReceiptDataPtr = aReceipt->getData();
		const auto ReceiptData = *ReceiptDataPtr;

		StatisticsFile << "\n--------";
		StatisticsFile << "\nOrder Type: " << std::get<2>(ReceiptData)<< " Time: " << std::get<0>(ReceiptData) ;
		for (const pair<const string, float> &item : std::get<1>(ReceiptData))
		{
			StatisticsFile << " Item: " << item.first << ": " << "Cost: "<< item.second ;
		}
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

//overriding the subject interface
void Statistics::AttachObserver(IObserver* observer)
{
	record_observer.push_back(observer);
}

void Statistics::DetachObserver(IObserver* observer)
{
	record_observer.remove(observer);
}
void Statistics::NotifyObservers()
{
	for (IObserver* observer : record_observer)
	{
		observer->Update("Statistics updated");
	}
}