#pragma once
#include<iostream>
#include <memory>
class IObserver
{
public:
	virtual ~IObserver() {};
	virtual void Update(float temp, float humidity, float pressure) = 0;
};