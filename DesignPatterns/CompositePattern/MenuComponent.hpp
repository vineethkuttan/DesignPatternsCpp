#pragma once
#include<iostream>
class MenuComponent
{
public:
	virtual void add(std::shared_ptr<MenuComponent> menuComponent)
	{
		throw std::runtime_error("UnsupportedOperationException");
	}
	virtual void remove(std::shared_ptr<MenuComponent> menuComponent)
	{
		throw std::runtime_error("UnsupportedOperationException");
	}
	virtual std::shared_ptr<MenuComponent> getChild(int i)
	{
		throw std::runtime_error("UnsupportedOperationException");
	}
	virtual std::string getName()
	{
		throw std::runtime_error("UnsupportedOperationException");
	}
	virtual std::string getDescription()
	{
		throw std::runtime_error("UnsupportedOperationException");
	}
	virtual double getPrice()
	{
		throw std::runtime_error("UnsupportedOperationException");
	}
	virtual bool isVegetarian()
	{
		throw std::runtime_error("UnsupportedOperationException");
	}
	virtual void print()
	{
		throw std::runtime_error("UnsupportedOperationException");
	}
};