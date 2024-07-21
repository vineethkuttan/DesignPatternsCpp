#pragma once
#include "MenuItem.hpp"
#include<memory>
class Iterator
{
public:
	virtual bool hasNext()=0;
	virtual std::shared_ptr<MenuItem> next()=0;
};