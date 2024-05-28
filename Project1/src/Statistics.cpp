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
		while (getline(StatisticsFile, line))
		{
			istringstream StringStream(line);

			cout << line << endl;
		}
	}
}

void Statistics::WriteRecord(Receipt *aReceipt)
{
	ofstream StatisticsFile("StatisticsDatabase/PurchaseRecords.txt");

	if (StatisticsFile.is_open())
	{
		unique_ptr<tuple<char *, multimap<string, float>, string, float>> ReceiptDataPtr = aReceipt->getData();
		const auto ReceiptData = *ReceiptDataPtr;

		for (const pair<const string, float> &item : std::get<1>(ReceiptData))
		{
<<<<<<< HEAD
			auto data = receipt.getData();
			multimap<string, float> itemsPurchased;
			time_t timeOfPurchase;
			string deliveryType;
			float total;

			// unpack the tuple
			tie(timeOfPurchase, itemsPurchased, deliveryType, total) = data;

			// write data to file
			StatisticsFile << itemsPurchased << "," << timeOfPurchase << "," << deliveryType << "," << total << "\n";
=======
			StatisticsFile << "Item: " << item.first << ": " << "Cost: " << item.second << std::endl;
>>>>>>> b30c640eee30351a3f9c06f47362fc8ca1f109b7
		}

		StatisticsFile << "Time: " << std::get<0>(ReceiptData) << "Order Type: " << std::get<2>(ReceiptData);

		StatisticsFile.close();
	}
	else
	{
<<<<<<< HEAD
		cout << "Error to opening file";
		return;
	}
}

/*string Statistics::DisplayStatistics()
{

}*/


=======
		std::cout << "File could not be open";
	}
}

void Statistics::DisplayStatistics()
{
	// Look through a document and grab the variables and pass the two variables into an array

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
>>>>>>> b30c640eee30351a3f9c06f47362fc8ca1f109b7
