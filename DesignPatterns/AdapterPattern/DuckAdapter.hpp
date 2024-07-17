#pragma once
#include "Turkey.hpp"
#include <random>

class DuckAdapter :public Turkey
{
private:
	shared_ptr<Duck> duck;
	std::random_device dev;
	std::mt19937 rng{ dev() };
	std::uniform_int_distribution<std::mt19937::result_type> dist5{ 0, 5 };
public:
	DuckAdapter(shared_ptr<Duck> _duck) {
		duck = _duck;
	}

	void gobble() override
	{
		duck->quack();
	}

	void fly() override
	{
		if (dist5(rng) == 0)
		{
			duck->fly();
		}
	}
};
