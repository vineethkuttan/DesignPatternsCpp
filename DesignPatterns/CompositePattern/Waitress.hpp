#pragma once
#include"Menu.hpp"
class Waitress
{
	std::shared_ptr<MenuComponent> allMenus;

public:
	Waitress(std::shared_ptr<MenuComponent> _allMenus)
	{
		allMenus = _allMenus;
	}

	void printMenu()
	{
		allMenus->print();
	}
};