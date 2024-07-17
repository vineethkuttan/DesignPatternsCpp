#pragma once
#include<iostream>
#include<memory>
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
#define string std::string
#define cout std::cout

class IBookParser
{
public:
	virtual int getNoOfPages() = 0;
};