#pragma once
#include<iostream>
#include<string>
class MenuItem
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
	std::string getName() {
		return name;
	}

	std::string getDescription() {
		return description;
	}

	double getPrice() {
		return price;
	}

	bool isVegetarian() {
		return vegetarian;
	}
	std::string tosString() {
		return std::string(name + ", $" + std::to_string(price) + "\n   " + description);
	}
};