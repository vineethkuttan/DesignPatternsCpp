#pragma once
#include "CdPlayer.hpp"
class PopcornPopper
{
private:
	string description;
public:
	PopcornPopper(string _description)
	{
		description = _description;
	}
	void on()
	{
		cout << description.c_str() << " on\n";
	}
	void off() {
		cout << description.c_str() << " off\n";
	}
	void pop() {
		cout << description.c_str() << " popping popcorn!\n";
	}
	string toString() {
		return description;
	}
};