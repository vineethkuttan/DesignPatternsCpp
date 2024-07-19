#pragma once
#include<iostream>
class CaffeineBeverageWithHook
{
public:
	virtual void prepareRecipe() final
	{
		boilWater();
		brew();
		pourInCup();
		if (customerWantsCondiments()) {
			addCondiments();
		}
	}

	virtual void brew() = 0;

	virtual void addCondiments() = 0;

	void boilWater()
	{
		printf("Boiling water\n");
	}

	void pourInCup()
	{
		printf("Pouring into cup");
	}

	virtual bool customerWantsCondiments()//hook
	{
		return true;
	}
};
