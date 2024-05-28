#include <chrono>
#include <iostream>

#include "Menu.h"
#include "Order.h"
#include "Reservation.h"
#include "Statistics.h"
#include "xWaiter.h"

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
	Reservation* reservation = new Reservation;
	Statistics& statistics = Statistics::GetInstance();

	//////////////////
	//unique_ptr<Staff> staff = Staff::createStaff("Waiter");
	xWaiter* waiter1 = new xWaiter(*reservation);
	//reservation->Attach(Staff::createStaff("Waiter"));
	///////////////////


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
			//Write order records to database8
			statistics.DisplayStatistics();
			break;
		default:
			std::cout << "Please make a valid selection of what you would like to do!\n";
			break;
		}
		std::cout << "==================================================================\n";
	}
	/* End of Shopping Section */
	
	return 0;
}