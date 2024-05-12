#include <iostream>
#include "Menu.h"
#include "Order.h"

int main()
{
	std::cout << "Hello me!" << std::endl;

	bool bIsShopping = true;
	
	Menu* menu = new Menu();
	Order* order = new Order();

	//Customer Cart
	std::map<std::string, float> Cart = menu->GetMenuItems();
	
	int Selection = 0;
	while (bIsShopping)
	{
		/* Shopping Section */
		std::cout << "Welcome to the Relaxing Koala!\n";
		std::cout << "Please make a selection of what you would like to do!\n";
		std::cout << "1 - Browse Menu\n";
		std::cout << "2 - Add to Order\n";
		std::cout << "3 - Remove from Order\n";
		std::cout << "4 - View Order\n";
		std::cout << "5 - Checkout\n";
		std::cout << "6 - Exit\n";

		std::cin >> Selection;

		switch (Selection)
		{
		case 1:
			//Presents Menu items to screen
			menu->ShowMenuItems();
			break;
		case 2:
			//Add to Customers Order
			order->AddToOrder("Latte", 3.0f);
			order->AddToOrder("Sandwich", 5.0f);
			order->AddToOrder("Long-Black", 3.0f);
			break;
		case 3:
			//Remove from Customers Order
			order->RemoveFromOrder("Latte");
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
			//Exit Shop and close application
			bIsShopping = false;
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