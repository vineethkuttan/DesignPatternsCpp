#pragma once
#include "CaffeineBeverageWithHook.hpp"
#include "CaffeineBeverage.hpp"

class Tea :public CaffeineBeverage
{
public:
	void brew() override
	{
		printf("Steeping the tea\n");
	}
	void addCondiments() override
	{
		printf("Adding Lemon\n");
	}
};

class TeaWithHook :public CaffeineBeverageWithHook 
{

public:
	void brew() override
	{
		printf("Steeping the tea\n");
	}

	void addCondiments() override
	{
		printf("Adding Lemon\n");
	}

	bool customerWantsCondiments()
	{
		std::string answer;
		printf("\n Do you want to add condiments\n");
		std::cin >> answer;
		if (answer == "YES")
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	
};