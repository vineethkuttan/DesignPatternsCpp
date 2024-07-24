#pragma once
#include "State.hpp"
#include<memory>
class GumballMachine
{
private:
	std::shared_ptr<State> soldOutState;
	std::shared_ptr<State> noQuarterState;
	std::shared_ptr<State> hasQuarterState;
	std::shared_ptr<State> soldState;
	std::shared_ptr<State> winnerState;
	std::shared_ptr<State> state;
	int count;
public:
	GumballMachine(int numberGumballs);
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void setState(std::shared_ptr<State> _state);
	void releaseBall();
	int getCount();
	void refill(int _count);
	std::shared_ptr<State> getState();
	std::shared_ptr<State> getSoldOutState();
	std::shared_ptr<State> getNoQuarterState();
	std::shared_ptr<State> getHasQuarterState();
	std::shared_ptr<State> getSoldState();
	std::shared_ptr<State> getWinnerState();
	std::string toString();
};