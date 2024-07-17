#pragma once
#include "Device.hpp"

class RemoteControl
{
protected:
	shared_ptr<Device> device;
public:
	RemoteControl(shared_ptr<Device>& _device)
		:device(_device)
	{
	}
	virtual void turnOn()
	{
		device->turnOn();
	}
	virtual void turnOff()
	{
		device->turnOff();
	}
};

class AdvancedRemoteControl :public RemoteControl
{
public:
	AdvancedRemoteControl(shared_ptr<Device>& _device)
		:RemoteControl(_device)
	{
	}
	void turnOn() override
	{
		device->turnOn();
	}
	void turnOff() override
	{
		device->turnOff();
	}
	void setChannel(int val)
	{
		device->setChannel(val);
	}
};