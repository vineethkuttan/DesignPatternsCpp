#pragma once
#include "CaffeineBeverageWithHook.hpp"
#include "CaffeineBeverage.hpp"

class Coffee :public CaffeineBeverage
{
public:
	void brew() override
	{
		printf("Dripping Coffee through filter\n");
	}
	void addCondiments() override
	{
		printf("Adding Sugar and Milk\n");
	}
};

class CoffeeWithHook :public CaffeineBeverageWithHook
{

public:
	void brew() override
	{
		printf("Dripping Coffee through filter\n");
	}

	void addCondiments() override
	{
		printf("Adding Sugar and Milk\n");
	}

	bool customerWantsCondiments() 
	{
		std::string answer ;
		printf("\n Do you want to add condiments\n");
		std::cin >> answer;
		if (answer=="YES")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};