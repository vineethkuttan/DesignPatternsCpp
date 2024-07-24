#pragma once
#include<iostream>
#include "GumballMachine.h"
#include "SoldOutState.hpp"
#include "SoldState.hpp"
#include "NoQuarterState.hpp"
#include "HasQuarterState.hpp"
#include "WinnerState.hpp"
#include<string>

GumballMachine::GumballMachine(int numberGumballs)
{
	soldOutState = std::make_shared<SoldOutState>(this);
	noQuarterState = std::make_shared<NoQuarterState>(this);
	hasQuarterState = std::make_shared<HasQuarterState>(this);
	soldState = std::make_shared<SoldState>(this);
	winnerState = std::make_shared<WinnerState>(this);
	state = soldOutState;
	count = numberGumballs;
	if (numberGumballs > 0)
	{
		state = noQuarterState;
	}
}

void GumballMachine::insertQuarter()
{
	state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
	state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
	state->turnCrank();
	state->dispense();
}

void GumballMachine::setState(std::shared_ptr<State> _state)
{
	state = state;
}

void GumballMachine::releaseBall()
{
	printf("A gumball comes rolling out the slot...\n");
	if (count > 0)
	{
		count = count - 1;
	}
}

int GumballMachine::getCount()
{
	return count;
}

void GumballMachine::refill(int _count)
{
	count += _count;
	printf("The gumball machine was just refilled; its new count is: %d\n", count);
	state->refill();
}

std::shared_ptr<State> GumballMachine::getState()
{
	return state;
}

std::shared_ptr<State> GumballMachine::getSoldOutState()
{
	return soldOutState;
}

std::shared_ptr<State> GumballMachine::getNoQuarterState()
{
	return noQuarterState;
}

std::shared_ptr<State> GumballMachine::getHasQuarterState()
{
	return hasQuarterState;
}

std::shared_ptr<State> GumballMachine::getSoldState()
{
	return soldState;
}

std::shared_ptr<State> GumballMachine::getWinnerState()
{
	return winnerState;
}

std::string GumballMachine::toString()
{
	std::string result;
	result.append("\nMighty Gumball, Inc.");
	result.append("\nJava-enabled Standing Gumball Model #2004");
	result.append(std::string("\nInventory: " + std::to_string(count) + " gumball"));
	if (count != 1)
	{
		result.append("s");
	}
	result.append("\n");
	result += std::string("Machine is ") + state->toString() + std::string("\n");;
	return result;
}