#pragma once
#include "Beverage.hpp"
class CondimentDecorator : public IBeverage {
public:
    shared_ptr<IBeverage> beverage_;
	//virtual int Cost() const = 0;
};

class Mocha :public CondimentDecorator {
public:
	Mocha(shared_ptr<IBeverage>& beverage) {
		beverage_=beverage;
	}
	int Cost() const override {
		return 2 + beverage_->Cost();
	}
};

class Milk :public CondimentDecorator {
public:
	Milk(shared_ptr<IBeverage>& beverage) {
		beverage_ = beverage;
	}
	int Cost() const override {
		return 3 + beverage_->Cost();
	}
};