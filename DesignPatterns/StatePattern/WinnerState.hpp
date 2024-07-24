#pragma once
#include "GumballMachine.h"
class WinnerState :public State
{
	GumballMachine* gumballMachine;
public:
	WinnerState(GumballMachine* _gumballMachine)
	{
		gumballMachine = _gumballMachine;
	}

	void insertQuarter() override
	{
		printf("Please wait, we're already giving you a Gumball\n");
	}

	void ejectQuarter() override
	{
		printf("Please wait, we're already giving you a Gumball\n");
	}

	void turnCrank() override
	{
		printf("Turning again doesn't get you another gumball!\n");
	}

	void dispense() override
	{
		gumballMachine->releaseBall();
		if (gumballMachine->getCount() == 0)
		{
			gumballMachine->setState(gumballMachine->getSoldOutState());
		}
		else {
			gumballMachine->releaseBall();
			printf("YOU'RE A WINNER! You got two gumballs for your quarter\n");
			if (gumballMachine->getCount() > 0) {
				gumballMachine->setState(gumballMachine->getNoQuarterState());
			}
			else {
				printf("Oops, out of gumballs!\n");
				gumballMachine->setState(gumballMachine->getSoldOutState());
			}
		}
	}

	void refill() override { }

	std::string toString() override
	{
		return "despensing two gumballs for your quarter, because YOU'RE A WINNER!";
	}
};