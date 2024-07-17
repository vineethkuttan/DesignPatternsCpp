#pragma once
#include<iostream>
#include<memory>
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
#define string std::string
#define cout std::cout

class Device
{
public:
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual void setChannel(int channel) = 0;
};

class SonyTv : public Device
{
public:
	void turnOn() override
	{
		cout << __FUNCTION__ << " Turned On\n";
	}
	void turnOff() override
	{
		cout << __FUNCTION__ << " Turned Off\n";
	}
	void setChannel(int channel) override
	{
		cout << __FUNCTION__ << " set Channel to "<<channel<<"\n";
	}
};

class SamsungTv : public Device
{
public:
	void turnOn() override
	{
		cout << __FUNCTION__ << " Turned On\n";
	}
	void turnOff() override
	{
		cout << __FUNCTION__ << " Turned Off\n";
	}
	void setChannel(int channel) override
	{
		cout << __FUNCTION__ << " set Channel to " << channel << "\n";
	}
};