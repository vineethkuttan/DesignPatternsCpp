#pragma once
#include "Button.hpp"
class CheckBox
{
public:
	virtual ~CheckBox() = default;
	virtual void paint() = 0;
};

class MacOsCheckBox :public CheckBox
{
public:
	void paint() override
	{
		printf("Painting MacOsCheckBox\n");
	}
};

class WindowsOsCheckBox :public CheckBox
{
public:
	void paint()
	{
		printf("Painting WindowsOsCheckBox\n");
	}
};