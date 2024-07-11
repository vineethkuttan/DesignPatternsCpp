#pragma once
#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"
#include <memory>
class Duck
{
private:
	std::unique_ptr<FlyBehavior> flyBehaviour_;
	std::unique_ptr<QuackBehavior> quackBehaviour_;
public:
	explicit Duck(std::unique_ptr<FlyBehavior>&& flyBehaviour = {}, std::unique_ptr<QuackBehavior>&& quackBehaviour = {}) 
		: flyBehaviour_(std::move(flyBehaviour)), quackBehaviour_(std::move(quackBehaviour))
	{
	}
	virtual void display()
	{
		printf("Normal Duck");
	}
	void performQuack()
	{
		quackBehaviour_->quack();
	}
	void performFly()
	{
		flyBehaviour_->fly();
	}
	void setFlyBehavior(std::unique_ptr<FlyBehavior>&& flyBehaviour)
	{
		flyBehaviour_ = std::move(flyBehaviour);
	}
	void setQuackBehavior(std::unique_ptr<QuackBehavior>&& quackBehaviour)
	{
		quackBehaviour_ = std::move(quackBehaviour);
	}
};

class MallardDuck :public  Duck {
public:
	MallardDuck() :
		Duck(std::move(std::make_unique<FlyWithWings>()), std::move(std::make_unique<Quack>()))
	{

	}
	void display() {
		printf("I'm a real Mallard duck");
	}
};