#pragma once
#include "GumballMachine.h"
class HasQuarterState : public State
{
	GumballMachine* gumballMachine;
public:
	HasQuarterState(GumballMachine* _gumballMachine)
	{
		gumballMachine = _gumballMachine;
	}

	void insertQuarter() override
	{
		printf("You can't insert another quarter\n");
	}

	void ejectQuarter() override
	{
		printf("Quarter returned\n");
		gumballMachine->setState(gumballMachine->getNoQuarterState());
	}

	void turnCrank() override
	{
		printf("You turned...\n");
		if ((gumballMachine->getCount()%10==0) && (gumballMachine->getCount() > 1))
		{
			gumballMachine->setState(gumballMachine->getWinnerState());
		}
		else
		{
			gumballMachine->setState(gumballMachine->getSoldState());
		}
	}

	void dispense() override
	{
		printf("No gumball dispensed\n");
	}

	void refill() override
	{ }

	std::string toString() override
	{
		return "waiting for turn of crank";
	}
};