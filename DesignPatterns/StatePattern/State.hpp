#pragma once
#include<string>
class State
{
public:
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;
	virtual void refill() = 0;
	virtual std::string toString() = 0;
};