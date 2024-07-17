#pragma once
#include "Amplifier.hpp"
class Projector
{
private:
	string description;
	shared_ptr<StreamingPlayer> player;

public:
	Projector(string _description, shared_ptr<StreamingPlayer>& _player) {
		description = _description;
		player = _player;
	}
	void on()
	{
		cout << description.c_str() << " on\n";
	}
	void off()
	{
		cout << description.c_str() << " off\n";
	}
	void wideScreenMode()
	{
		cout << description.c_str() << " in widescreen mode (16x9 aspect ratio)\n";
	}
	void tvMode()
	{
		cout << description.c_str() << " in tv mode (4x3 aspect ratio)\n";
	}
	string toString()
	{
		return description;
	}
};
