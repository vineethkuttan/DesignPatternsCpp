#pragma once
#include "GumballMachine.h"
class NoQuarterState :public State
{
	GumballMachine* gumballMachine;

public:
	NoQuarterState(GumballMachine* _gumballMachine)
	{
		gumballMachine = _gumballMachine;
	}

	void insertQuarter() override
	{
		printf("You inserted a quarter\n");
		gumballMachine->setState(gumballMachine->getHasQuarterState());
	}

	void ejectQuarter() override
	{
		printf("You haven't inserted a quarter\n");
	}

	void turnCrank() override
	{
		printf("You turned, but there's no quarter\n");
	}

	void dispense() override
	{
		printf("You need to pay first\n");
	}

	void refill() override
	{
	}
	
	std::string toString() override
	{
		return "waiting for quarter";
	}
};