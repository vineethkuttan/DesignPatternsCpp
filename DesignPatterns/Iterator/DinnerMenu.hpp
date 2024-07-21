#pragma once
#include "Menu.hpp"
#include<vector>
#define MAX_ITEMS 6

class DinerMenuIterator :public Iterator
{
	std::vector<std::shared_ptr<MenuItem>> items;
	int position;
public:
	DinerMenuIterator(std::vector<std::shared_ptr<MenuItem>>& _items)
	{
		position = 0;
		items = _items;
	}

	std::shared_ptr<MenuItem> next() {
		return items[position++];
	}

	bool hasNext()
	{
		return items.size() > position;
	}
};

class DinerMenu:public Menu
{
private:
	std::vector<std::shared_ptr<MenuItem>> menuItems;

public:
	DinerMenu()
	{
		addItem("Vegetarian BLT","(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
		addItem("BLT","Bacon with lettuce & tomato on whole wheat", false, 2.99);
		addItem("Soup of the day","Soup of the day, with a side of potato salad", false, 3.29);
		addItem("Hotdog","A hot dog, with sauerkraut, relish, onions, topped with cheese",false, 3.05);
		addItem("Steamed Veggies and Brown Rice","Steamed vegetables over brown rice", true, 3.99);
		addItem("Pasta","Spaghetti with Marinara Sauce, and a slice of sourdough bread",true, 3.89);
	}

	void addItem(std::string name, std::string description,	bool vegetarian, double price)
	{
		std::shared_ptr<MenuItem> menuItem = std::make_shared<MenuItem>(name, description, vegetarian, price);
		if (menuItems.size() >= MAX_ITEMS) {
			printf("Sorry, menu is full!  Can't add item to menu\n");
		}
		else 
		{
			menuItems.push_back(menuItem);
		}
	}

	std::vector<std::shared_ptr<MenuItem>>& getMenuItems()
	{
		return menuItems;
	}

	std::shared_ptr<Iterator> createIterator()
	{
		return std::make_shared<DinerMenuIterator>(menuItems);
	}

};