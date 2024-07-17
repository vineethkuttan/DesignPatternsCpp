#include "Screen.hpp"

class TheaterLights
{
	string description;

public:
	TheaterLights(string _description)
	{
		description = _description;
	}

	void on()
	{
		cout << description.c_str() << " on";
	}

	void off()
	{
		cout << description.c_str() << " off";
	}

	void dim(int level)
	{
		cout << description.c_str() << " dimming to " << level << "%\n";
	}

	string toString()
	{
		return description;
	}
};