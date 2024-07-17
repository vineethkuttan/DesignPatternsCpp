#pragma once
#include "Duck.hpp"

class Turkey {
public:
	virtual void gobble() = 0;
	virtual void fly() = 0;
};

class WildTurkey :public Turkey {
public:
	void gobble() override
	{
		printf("Gobble gobble\n");
	}

	void fly() override
	{
		printf("I'm flying a short distance\n");
	}
};