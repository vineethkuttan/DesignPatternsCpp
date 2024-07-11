#pragma once
#include<iostream>
#include <memory>
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
class IBeverage
{
public:
	virtual ~IBeverage() {};
	virtual int Cost() const = 0;
};

class Espresso : public IBeverage
{
public:
	int Cost() const override {
		return 5;
	}
};
class Decaf : public IBeverage
{
public:
	int Cost() const override {
		return 10;
	}
};