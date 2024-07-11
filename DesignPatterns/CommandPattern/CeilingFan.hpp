#pragma once
#include "ICommand.hpp"

enum Speed {OFF,LOW,MEDIUM,HIGH};
class CeilingFan {
public:
	string location;
	Speed speed;

	CeilingFan(string location) 
	{
		this->location = location;
		speed = Speed::OFF;
	}

	void high() {
		speed = Speed::HIGH;
		printf("%s ceiling fan is on high\n", location.c_str());
	}

	void medium() {
		speed = Speed::MEDIUM;
		printf("%s ceiling fan is on medium\n", location.c_str());
	}

	void low() {
		speed = Speed::LOW;
		printf("%s ceiling fan is on low\n", location.c_str());
	}

	void off() {
		speed = Speed::OFF;
		printf("%s ceiling fan is off\n", location.c_str());
	}

	int getSpeed() {
		return speed;
	}
};

class CeilingFanHighCommand :public ICommand
{
	shared_ptr<CeilingFan> ceilingFan;
	int prevSpeed;

public:
	CeilingFanHighCommand(shared_ptr<CeilingFan>& ceilingFan)
	{
		this->ceilingFan = ceilingFan;
	}

	void Execute() override
	{
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->high();
	}

	void Undo() override
	{
		if (prevSpeed == Speed::HIGH)
		{
			ceilingFan->high();
		}
		else if (prevSpeed == Speed::MEDIUM)
		{
			ceilingFan->medium();
		}
		else if (prevSpeed == Speed::LOW)
		{
			ceilingFan->low();
		}
		else if (prevSpeed == Speed::OFF)
		{
			ceilingFan->off();
		}
	}
};

class CeilingFanLowCommand :public ICommand
{
	shared_ptr<CeilingFan> ceilingFan;
	int prevSpeed;

public:
	CeilingFanLowCommand(shared_ptr<CeilingFan>& ceilingFan)
	{
		this->ceilingFan = ceilingFan;
	}

	void Execute() override
	{
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->low();
	}

	void Undo() override
	{
		if (prevSpeed == Speed::HIGH)
		{
			ceilingFan->high();
		}
		else if (prevSpeed == Speed::MEDIUM)
		{
			ceilingFan->medium();
		}
		else if (prevSpeed == Speed::LOW)
		{
			ceilingFan->low();
		}
		else if (prevSpeed == Speed::OFF)
		{
			ceilingFan->off();
		}
	}
};

class CeilingFanMediumCommand :public ICommand
{
	shared_ptr<CeilingFan> ceilingFan;
	int prevSpeed;

public:
	CeilingFanMediumCommand(shared_ptr<CeilingFan>& ceilingFan)
	{
		this->ceilingFan = ceilingFan;
	}

	void Execute() override
	{
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->medium();
	}

	void Undo() override
	{
		if (prevSpeed == Speed::HIGH)
		{
			ceilingFan->high();
		}
		else if (prevSpeed == Speed::MEDIUM)
		{
			ceilingFan->medium();
		}
		else if (prevSpeed == Speed::LOW)
		{
			ceilingFan->low();
		}
		else if (prevSpeed == Speed::OFF)
		{
			ceilingFan->off();
		}
	}
};

class CeilingFanOffCommand :public ICommand
{
	shared_ptr<CeilingFan> ceilingFan;
	int prevSpeed;

public:
	CeilingFanOffCommand(shared_ptr<CeilingFan>& ceilingFan)
	{
		this->ceilingFan = ceilingFan;
	}

	void Execute() override
	{
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->medium();
	}

	void Undo() override
	{
		if (prevSpeed == Speed::HIGH)
		{
			ceilingFan->high();
		}
		else if (prevSpeed == Speed::MEDIUM)
		{
			ceilingFan->medium();
		}
		else if (prevSpeed == Speed::LOW)
		{
			ceilingFan->low();
		}
		else if (prevSpeed == Speed::OFF)
		{
			ceilingFan->off();
		}
	}
};