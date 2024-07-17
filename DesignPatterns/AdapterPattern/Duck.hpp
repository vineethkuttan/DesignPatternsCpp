#include<iostream>
#include<memory>
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
#define string std::string

class Duck {
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallardDuck :public Duck {
public:
	void quack() override
	{
		printf("Quack\n");
	}

	void fly() override
	{
		printf("I'm flying\n");
	}
};