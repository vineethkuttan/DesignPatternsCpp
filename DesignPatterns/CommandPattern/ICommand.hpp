#pragma once
#include<iostream>
#include<memory>
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
#define string std::string

class ICommand
{
public:
	//virtual ~ICommand();
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

class NoCommand :public ICommand
{
public:
	void Execute()
	{
		printf("No Command Allocates Here\n");
	}
	void Undo()
	{
		printf("No Command Allocates Here\n");
	}
};