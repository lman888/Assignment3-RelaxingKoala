#include <iostream>
#include "Menu.h"
#include "Order.h"
#include "Reservation.h"
#include "Statistics.h"
#include "OrderObserver.h"
#include "ReservationObserver.h"
#include "Staff.h"
#include "Payment.h"

void ShowCustomerSelections()
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
void ShowWaitStaffSelections()
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
void ShowKitchenStaffSelections()
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
void ShowDeliveryStaffSelections()
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
void ShowOwnerSelections()
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
int LoginMenu() { //new main()
	std::cout << "Hello me!" << std::endl;
	int loginChoice;
	std::cin >> loginChoice;
	switch (loginChoice) {
	case 1:
		std::cout << "Hello customer!" << std::endl;
		//customerMenu();
		break;
	case 2:
		std::cout << "Hello wait staff!" << std::endl;
		//waitStaffMenu();
		break;
	case 3:
		std::cout << "Hello kitchen staff!" << std::endl;
		//kitchenStaffMenu();
		break;
	case 4:
		std::cout << "Hello delivery staff!" << std::endl;
		//deliveryStaffChoice();
		break;
	case 5:
		std::cout << "Hello owner!" << std::endl;
		//ownerMenu();
		break;
	default:
		std::cout << "Enter a valid number\n";
		break;
	}
	return 0;
}
int WaiterMenu() {
	int waitStaffChoice;
	std::cin >> waitStaffChoice;
	switch (waitStaffChoice) {
	case 1:
		std::cout << "choice 1" << std::endl;
		break;
	case 2:
		std::cout << "choice 2" << std::endl;
		break;
	default:
		std::cout << "Enter a valid number\n";
		break;
	}
	return 0;
}
int KitchenStaffMenu() {
	int kitchenStaffChoice;
	std::cin >> kitchenStaffChoice;
	switch (kitchenStaffChoice) {
	case 1:
		std::cout << "choice 1" << std::endl;
		break;
	case 2:
		std::cout << "choice 2" << std::endl;
		break;
	default:
		std::cout << "Enter a valid number\n";
		break;
	}
	return 0;
}
int DeliveryStaffMenu() {
	int deliveryStaffChoice;
	std::cin >> deliveryStaffChoice;
	switch (deliveryStaffChoice) {
	case 1:
		std::cout << "choice 1" << std::endl;
		break;
	case 2:
		std::cout << "choice 2" << std::endl;
		break;
	default:
		std::cout << "Enter a valid number\n";
		break;
	}
	return 0;
}
int OwnerMenu() {
	int ownerChoice;
	std::cin >> ownerChoice;
	switch (ownerChoice) {
	case 1:
		std::cout << "choice 1" << std::endl;
		break;
	case 2:
		std::cout << "choice 2" << std::endl;
		break;
	default:
		std::cout << "Enter a valid number\n";
		break;
	}
	return 0;
}
int main()//CustomerMenu()
{
	std::cout << "Hello me!" << std::endl;

	bool bIsShopping = true;

	Menu *menu = new Menu();
	Order *order = new Order(menu);
	Reservation *reservation = new Reservation();
	Statistics &statistics = Statistics::GetInstance();
	Payment* payment = new Payment();

	

	//Instantiating temporary xWaiter class object and allowing it to observe reservations
	//xWaiter* waiter1 = new xWaiter(*reservation);
	//xKitchen* kitchen1 = new xKitchen(*order); 
	/*xWaiter* waiter2 = new xWaiter(*reservation);
	reservation->DetachObserver(waiter2);
	waiter2 = new xWaiter(*reservation);
	waiter2->~xWaiter();
	waiter2->RemoveMeFromTheList();*/


	//stefanus's
	//std::unique_ptr<Staff> waiter1 = Staff::createStaff("Waiter", *reservation);

	// Customer Cart
	std::map<std::string, float> Cart = menu->GetMenuItems();

	/* Shopping Section */
	std::cout << "Welcome to the Relaxing Koala!\n";
	std::cout << "Please make a selection of what you would like to do!\n";
	
	ShowCustomerSelections();
	std::cout << "=================================\n";
	int Selection, Selection2 = 0;
	std::string input;
	
	while (bIsShopping)
	{	
		int customerSelection;
		
		std::string input;
		std::getline(std::cin, input);
		try
		{
			customerSelection = std::stoi(input);
		}
		catch (const std::exception& e)
		{
			std::cout << "Please enter a number\n";
			continue;
		}
		switch (customerSelection)
		{
		case 1:
			// Presents Menu items to screen
			menu->ShowMenuItems();
			break;
		case 2:
			// Add to Customers Order
			std::cout << "Please select an Order Item\n";
			menu->ShowMenuItems();
			std::cin >> input;
			order->AddToOrder(input);
			break;
		case 3:
			// Remove from Customers Order
			std::cout << "Please select what item you wish to remove\n";
			order->ShowOrder();
			std::cin >> input;
			order->RemoveFromOrder(input);
			break;
		case 4:
			// Shows Customers Order
			order->ShowOrder();
			order->ShowTotalCost();
			break;
		case 5:
			// Checkout
			std::cout << "Checkout Here!\n";
			order->ShowTotalCost();
			payment->initiatePayment();
			order->GenerateReceipt();

			//Observer Pattern at work
			order->MessageToBeNotifiedToObservers("A new order has been confirmed");

			//Continue? menu
			std::cout << "Make another order?\n";
			std::cout << "1 - Yes\n";
			std::cout << "2 - No (Exit application)\n";
			cin >> Selection2;
			switch (Selection2)
			{
			case 1:
				//Make another order
				//order->ClearOrder();
				break;
			case 2:
				//Exit application
				return 0;
			default:
				std::cout << "Please make a valid selection of what you would like to do!\n";
				break;
			}
			break;
		case 6:
			// Table Reservation Menu
			std::cout << "Reserve a table here! (Main.cpp)\n";
			std::cout << "1 - Add a reservation\n";
			std::cout << "2 - Remove a reservation\n";
			std::cout << "Reserve a table here! (Main.cpp)\n";

			std::cin >> Selection2;
			switch (Selection2)
			{
			case 1:
				//Make a reservation
				reservation->AddReservation();
				break;
			case 2:
				//Remove a reservation
				reservation->RemoveReservation();
				break;
			default:
				std::cout << "Please make a valid selection of what you would like to do!\n";
				break;
			}
			break;
		case 7:
			// Exit Shop and close application
			bIsShopping = false;
			return 0;
		case 8:
			// Write order records to database8
			statistics.DisplayStatistics();
			break;
		default:
			std::cout << "Please select a valid number!\n";
			break;
		}
		std::cout << "==================================================================\n";
		ShowCustomerSelections();
		std::cout << "=================================\n"; 
		
		
		
	}
	/* End of Shopping Section */

	return 0;
}
