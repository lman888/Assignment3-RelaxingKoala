#pragma once
#include <string>
#include <map>

class Menu
{
public:
	Menu();
	~Menu() = default;

	//Returns a list of Menu Items
	void ShowMenuItems() const;
	
	std::map<std::string, float> GetMenuItems() const;

private:
	void RetrieveMenuFromDataBase();

	std::map<std::string, float> MenuItems;
};
