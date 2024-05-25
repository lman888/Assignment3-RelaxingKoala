#include <chrono>
#include <iostream>
#include <ctime>

#include "Menu.h"
#include "Order.h"
#include "Reservation.h"
#include "Statistics.h"

void ShowSelections()
{
	std::cout << "1 - Browse Menu\n";
	std::cout << "2 - Add to Order\n";
	std::cout << "3 - Remove from Order\n";
	std::cout << "4 - View Order\n";
	std::cout << "5 - Checkout\n";
	std::cout << "6 - Make a Reservation\n";
	std::cout << "7 - Exit\n";
	std::cout << "8 - Statistics\n";
}

int main()
{
	std::cout << "Hello me!" << std::endl;

	bool bIsShopping = true;
	
	Menu* menu = new Menu();
	Order* order = new Order(menu);
	Reservation* reservation = new Reservation();
	Statistics* statistics = new Statistics();

	int Selection2 = 0;//maybe remove later, cuz its only for option 6 -Amelie

	//Customer Cart
	std::map<std::string, float> Cart = menu->GetMenuItems();
	
	/* Shopping Section */
	std::cout << "Welcome to the Relaxing Koala!\n";
	std::cout << "Please make a selection of what you would like to do!\n";
	ShowSelections();
	
	int Selection = 0;
	std::string SelectedItem;
	while (bIsShopping)
	{
		std::string input;
		std::getline(std::cin, input);
		try
		{
			Selection = std::stoi(input);
		}
		catch (const std::exception& e)
		{
			continue;
		}
		
		switch (Selection)
		{
		case 1:
			//Presents Menu items to screen
			menu->ShowMenuItems();
			break;
		case 2:
			//Add to Customers Order
			std::cout << "Please select an Order Item\n";
			menu->ShowMenuItems();
			std::cin >> input;
			order->AddToOrder(input);
			break;
		case 3:
			//Remove from Customers Order
			std::cout << "Please select what item you wish to remove\n";
			order->ShowOrder();
			std::cin >> input;
			order->RemoveFromOrder(input);
			break;
		case 4:
			//Shows Customers Order
			order->ShowOrder();
			order->ShowTotalCost();
			break;
		case 5:
			//Checkout
			std::cout << "Checkout Here!\n";
			order->ShowTotalCost();
			order->GenerateReceipt();
			statistics->WriteRecord();  //write the rcord after recipt is created
			bIsShopping = false;
			break;
		case 6:
			//Make Reservation (WIP by Amelie) 
			//do i make the reservation menu here?

			std::cout << "Reserve a table here! (Main.cpp)\n";
			std::cout << "1 - Add a reservation\n";
			std::cout << "2 - Remove a reservation\n";
			std::cout << "Reserve a table here! (Main.cpp)\n";
			
			std::cin >> Selection2;
			switch (Selection2) {
			case 1:
				reservation->AddReservation();//COMPLETE
				break;
			case 2:
				reservation->RemoveReservation();//COMPLETE
				break;
			default:
				std::cout << "Please make a valid selection of what you would like to do!\n";
				break;
			}
			//no sanitising done yet, might completely remove this menu later
			
			break;
		case 7:
			//Exit Shop and close application
			bIsShopping = false;
			break;
		case 8:
			//Write order records to database
			statistics->WriteRecord();
			break;
		default:
			std::cout << "Please make a valid selection of what you would like to do!\n";
			break;
		}
		std::cout << "==================================================================\n";
	}
	/* End of Shopping Section */

	// Get the current time as a time_point
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

	// Convert the time_point to a time_t, which represents the time in seconds since the epoch
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	// Convert the time_t to a tm structure for local time in a thread-safe manner
	std::tm localTime;
	localtime_s(&localTime, &currentTime);

	// Create a buffer to store the formatted time string
	char timeString[26]; // asctime_s requires a buffer of at least 26 characters

	// Convert the tm structure to a human-readable string in a thread-safe manner
	asctime_s(timeString, sizeof(timeString), &localTime);

	// Print the time string
	std::cout << "Current time: " << timeString;
	
	return 0;
}