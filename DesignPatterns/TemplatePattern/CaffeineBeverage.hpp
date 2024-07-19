#pragma once
#include<iostream>
//#include<memory>
//#define unique_ptr std::unique_ptr
//#define shared_ptr std::shared_ptr
//#define string std::string
//#define cout std::cout

class CaffeineBeverage
{
public:
	virtual void prepareRecipe() final
	{
		boilWater();
		brew();
		pourInCup();
		addCondiments();
	}
	virtual void brew() = 0;

	virtual void addCondiments() = 0;

	virtual void boilWater()
	{
		printf("Boiling water\n");
	}

	virtual void pourInCup()
	{
		printf("Pouring into cup\n");
	}
};