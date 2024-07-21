#pragma once
#include "PanCakeHouseMenu.hpp"
class Waitress
{
	std::shared_ptr<Menu> pancakeHouseMenu;
	std::shared_ptr<Menu> dinerMenu;

public:
	Waitress(std::shared_ptr<Menu> _pancakeHouseMenu, std::shared_ptr<Menu> _dinerMenu)
	{
		pancakeHouseMenu = _pancakeHouseMenu;
		dinerMenu = _dinerMenu;
	}
	void printVegetarianMenu()
	{
		printVegetarianMenu(pancakeHouseMenu->createIterator());
		printVegetarianMenu(dinerMenu->createIterator());
	}

	bool isItemVegetarian(std::string name) {
		std::shared_ptr<Iterator> breakfastIterator = pancakeHouseMenu->createIterator();
		if (isVegetarian(name, breakfastIterator))
		{
			return true;
		}
		std::shared_ptr<Iterator> dinnerIterator = dinerMenu->createIterator();
		if (isVegetarian(name, dinnerIterator))
		{
			return true;
		}
		return false;
	}
	void printMenu()
	{
		std::shared_ptr<Iterator> pancakeIterator = pancakeHouseMenu->createIterator();
		std::shared_ptr<Iterator> dinerIterator = dinerMenu->createIterator();

		printf("MENU\n----\nBREAKFAST\n");
		printMenu(pancakeIterator);
		printf("\nLUNCH\n");
		printMenu(dinerIterator);

	}

private:
	void printMenu(std::shared_ptr<Iterator> iterator)
	{
		while (iterator->hasNext())
		{
			std::shared_ptr<MenuItem> menuItem = iterator->next();
			std::string hg = std::string(menuItem->getName() + ", \n" + std::to_string(menuItem->getPrice()) + " -- " + menuItem->getDescription());
			printf("%s\n", hg.c_str());
		}
	}
	void printVegetarianMenu(std::shared_ptr<Iterator> iterator)
	{
		while (iterator->hasNext())
		{
			std::shared_ptr<MenuItem> menuItem = iterator->next();
			if (menuItem->isVegetarian())
			{
				std::string hg = std::string(menuItem->getName() + ", \n" + std::to_string(menuItem->getPrice()) + " -- " + menuItem->getDescription());
				printf("%s\n", hg.c_str());
			}
		}
	}

	bool isVegetarian(std::string name, std::shared_ptr<Iterator> iterator)
	{
		while (iterator->hasNext())
		{
			std::shared_ptr<MenuItem> menuItem = iterator->next();
			if (menuItem->getName().compare(name) == 0)
			{
				if (menuItem->isVegetarian())
				{
					return true;
				}
			}
		}
		return false;
	}
};