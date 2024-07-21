#pragma once
#include "DinnerMenu.hpp"
#include<list>
class PancakeHouseMenuIterator:public Iterator
{
	std::list<std::shared_ptr<MenuItem>> items;
	std::list<std::shared_ptr<MenuItem>>::iterator it;

public:
	PancakeHouseMenuIterator(std::list<std::shared_ptr<MenuItem>>& _items)
	{
		items = _items;
		it = items.begin();
	}

	std::shared_ptr<MenuItem> next() 
	{
		std::list<std::shared_ptr<MenuItem>>::iterator temp_it = it;
		if (++temp_it !=items.end())
		{
			return *(++it);
		}
		return nullptr;
	}

	bool hasNext()
	{
		std::list<std::shared_ptr<MenuItem>>::iterator temp_it=it;
		if (++temp_it == items.end())
		{
			return false;
		}
		return true;
	}
};

class PancakeHouseMenu :public Menu
{
	std::list<std::shared_ptr<MenuItem>> menuItems;

public:
	PancakeHouseMenu() 
	{
		addItem("K&B's Pancake Breakfast","Pancakes with scrambled eggs and toast",true,2.99);
		addItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99);
		addItem("Blueberry Pancakes","Pancakes made with fresh blueberries",true,3.49);
		addItem("Waffles","Waffles with your choice of blueberries or strawberries",true,3.59);
	}

	void addItem(std::string name, std::string description,bool vegetarian, double price)
	{
		std::shared_ptr<MenuItem> menuItem = std::make_shared<MenuItem>(name, description, vegetarian, price);
		menuItems.push_back(menuItem);
	}

	std::list<std::shared_ptr<MenuItem>>& getMenuItems()
	{
		return menuItems;
	}

	std::shared_ptr<Iterator> createIterator() {
		return std::make_shared<PancakeHouseMenuIterator>(menuItems);
	}

	std::string toString() {
		return "Objectville Pancake House Menu";
	}
};