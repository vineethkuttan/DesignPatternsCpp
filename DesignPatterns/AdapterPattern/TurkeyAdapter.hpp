#pragma once
#include "DuckAdapter.hpp"
class TurkeyAdapter :public Duck {
	shared_ptr<Turkey> turkey;

public:
	TurkeyAdapter(shared_ptr<Turkey>& _turkey)
	{
		turkey = _turkey;
	}

	void quack() override
	{
		turkey->gobble();
	}

	void fly() override
	{
		for (int i = 0; i < 5; i++) {
			turkey->fly();
		}
	}
};