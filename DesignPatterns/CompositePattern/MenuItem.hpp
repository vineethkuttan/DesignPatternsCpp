#pragma once
#include "MenuComponent.hpp"
class MenuItem :public MenuComponent
{
private:
	std::string name;
	std::string description;
	bool vegetarian;
	double price;

public:
	MenuItem(std::string _name, std::string _description, bool _vegetarian, double _price)
	{
		name = _name;
		description = _description;
		vegetarian = _vegetarian;
		price = _price;
	}

	std::string getName() override
	{
		return name;
	}

	std::string getDescription() override
	{
		return description;
	}

	double getPrice() override
	{
		return price;
	}

	bool isVegetarian() override
	{
		return vegetarian;
	}

	void print() override
	{
		printf("  %s", getName().c_str());
		if (isVegetarian())
		{
			printf("(v)");
		}
		printf(", %lf\n", getPrice());
		printf("     -- %s\n", getDescription().c_str());
	}
};