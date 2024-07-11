#pragma once
#include "Checkbox.hpp"

class GuiFactory
{
public:
	virtual shared_ptr<Button> createButton()=0;
	virtual shared_ptr <CheckBox> createCheckbox()=0;
};

class MacOsFactory : public GuiFactory
{
public:
	shared_ptr<Button> createButton() override
	{
		return std::make_shared<MacOsButton>();
	}

	shared_ptr <CheckBox> createCheckbox()
	{
		return std::make_shared<MacOsCheckBox>();
	}
};

class WindowsOsFactory : public GuiFactory
{
public:
	shared_ptr<Button> createButton() override
	{
		return std::make_shared<WindowsOsButton>();
	}

	shared_ptr <CheckBox> createCheckbox()
	{
		return std::make_shared<WindowsOsCheckBox>();
	}
};