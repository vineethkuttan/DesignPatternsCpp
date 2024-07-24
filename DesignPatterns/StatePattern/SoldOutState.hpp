#pragma once
#include "GumballMachine.h"

class SoldOutState : public State {
	GumballMachine* gumballMachine;

public:
	SoldOutState(GumballMachine* _gumballMachine)
	{
		gumballMachine = _gumballMachine;
	}

	void insertQuarter() override
	{
		printf("You can't insert a quarter, the machine is sold out\n");
	}

	void ejectQuarter() override
	{
		printf("You can't eject, you haven't inserted a quarter yet\n");
	}

	void turnCrank() override
	{
		printf("You turned, but there are no gumballs\n");
	}

	void dispense() override
	{
		printf("No gumball dispensed\n");
	}

	void refill() override
	{
		gumballMachine->setState(gumballMachine->getNoQuarterState());
	}

	std::string toString() override
	{
		return "sold out";
	}
};