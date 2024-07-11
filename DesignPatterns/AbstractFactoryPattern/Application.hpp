#pragma once
#include "GuiFactory.hpp"

class Application
{
private:
	shared_ptr<Button> button;
	shared_ptr<CheckBox> checkbox;
public:
	Application(shared_ptr<GuiFactory>& factory)
	{
		button = factory->createButton();
		checkbox = factory->createCheckbox();
	}
	void paint()
	{
		button->paint();
		checkbox->paint();
	}
};