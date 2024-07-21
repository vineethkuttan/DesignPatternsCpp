#pragma once
#include "MenuItem.hpp"
#include<vector>
class Menu :public MenuComponent
{
	std::vector<std::shared_ptr<MenuComponent>> menuComponents;
	std::string name;
	std::string description;
public:

	Menu(std::string _name, std::string _description)
	{
		name = _name;
		description = _description;
	}
	void add(std::shared_ptr<MenuComponent> menuComponent) override
	{
		menuComponents.push_back(menuComponent);
	}

	void remove(std::shared_ptr<MenuComponent> menuComponent) override
	{
		//menuComponents.menuComponent);
	}

	std::shared_ptr<MenuComponent> getChild(int i) override
	{
		return	menuComponents.at(i);
	}

	std::string getName() override
	{
		return name;
	}

	std::string getDescription() override
	{
		return description;
	}

	void print() override
	{
		printf("\n%s", getName().c_str());
		printf(", %s\n", getDescription().c_str());
		printf("---------------------\n");

		std::vector<std::shared_ptr<MenuComponent>>::iterator iter = menuComponents.begin();
		while (++iter != menuComponents.end())
		{
			std::shared_ptr<MenuComponent> menuComponent = *iter;
			menuComponent->print();
		}
	}
};