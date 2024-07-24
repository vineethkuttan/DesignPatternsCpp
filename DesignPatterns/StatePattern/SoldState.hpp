#pragma once
#include "GumballMachine.h"

class SoldState :public State
{
	GumballMachine * gumballMachine;
public:
	SoldState(GumballMachine* _gumballMachine)
	{
		gumballMachine = _gumballMachine;
	}

	void insertQuarter() override
	{
		printf("Please wait, we're already giving you a gumball\n");
	}

	void ejectQuarter() override
	{
		printf("Sorry, you already turned the crank\n");
	}

	void turnCrank() override
	{
		printf("Turning twice doesn't get you another gumball!\n");
	}

	void dispense() override
	{
		gumballMachine->releaseBall() ;
		if (gumballMachine->getCount()  > 0)
		{
			gumballMachine->setState(gumballMachine->getNoQuarterState());
		}
		else
		{
			printf("Oops, out of gumballs!\n");
			gumballMachine->setState(gumballMachine->getSoldOutState());
		}
	}

	void refill() override
	{
	}

	std::string toString() override
	{
		return "dispensing a gumball";
	}
};