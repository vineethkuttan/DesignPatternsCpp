#include "Application.hpp"

int main()
{
	shared_ptr<Application> app;
	shared_ptr<GuiFactory> factory;
	factory.reset(new MacOsFactory());
	app.reset(new Application(factory));
	app->paint();
	return 0;
}