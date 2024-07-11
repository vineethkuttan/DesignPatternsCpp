#pragma once
#include "ICommand.hpp"
class Light {
	string location;
	int level;

public:
	Light(string location) 
	{
		this->location = location;
	}

	void on() 
	{
		level = 100;
		printf("Light is on\n");
	}

	void off()
	{
		level = 0;
		printf("Light is off\n");
	}

	void dim(int level) 
	{
		this->level = level;
		if (level == 0) {
			off();
		}
		else {
			printf("Light is dimmed to %d %\n" , level);
		}
	}

	int getLevel() {
		return level;
	}
};

class LightOffCommand :public ICommand {
	shared_ptr<Light> light;
	int level;
public:
	LightOffCommand(shared_ptr<Light> light)
	{
		this->light = light;
	}

	void Execute() override
	{
		level = light->getLevel();
		light->off();
	}

	void Undo() override
	{
		light->dim(level);
	}
};

class LightOnCommand :public ICommand {
	shared_ptr<Light> light;
	int level;
public:
	LightOnCommand(shared_ptr<Light>& light) 
	{
		this->light = light;
	}

	void Execute() override
	{
		level = light->getLevel();
		light->on();
	}

	void Undo() override
	{
		light->dim(level);
	}
};