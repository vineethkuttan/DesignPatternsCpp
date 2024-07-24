// StatePattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GumballMachine.h"

int main()
{
	GumballMachine gumballMachine(10);

	printf("%s",gumballMachine.toString().c_str());

	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();

	printf("%s",gumballMachine.toString().c_str());

	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();

	printf("%s",gumballMachine.toString().c_str());

	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();

	printf("%s",gumballMachine.toString().c_str());

	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();

	printf("%s",gumballMachine.toString().c_str());

	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();

	printf("%s",gumballMachine.toString().c_str());
}