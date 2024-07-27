#pragma once
#include<iostream>
class Component
{
public:
	virtual void render() = 0;
	virtual std::shared_ptr<Component> clone() = 0;
};