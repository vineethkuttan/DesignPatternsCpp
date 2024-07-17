#pragma once
#include "Projector.hpp"
class CdPlayer
{
private:
	string description;
	int currentTrack;
	shared_ptr<Amplifier> amplifier;
	string title;

public:
	CdPlayer(string _description, shared_ptr<Amplifier>& _amplifier)
	{
		description = _description;
		amplifier = _amplifier;
	}
	void on()
	{
		cout << description.c_str() << " on\n";
	}

	void off()
	{
		cout << description.c_str() << " off\n";
	}

	void eject()
	{
		title = "";
		cout << description.c_str() << " eject\n";
	}

	void play(string& _title)
	{
		title = _title;
		currentTrack = 0;
		cout << description.c_str() << " playing \"" << title << "\"\n";
	}

	void play(int track)
	{
		if (title == "")
		{
			cout << description.c_str() << " can't play track " << currentTrack << ", no cd inserted\n";
		}
		else
		{
			currentTrack = track;
			cout << description.c_str() << " playing track " << currentTrack << "\n";
		}
	}

	void stop()
	{
		currentTrack = 0;
		cout << description.c_str() << " stopped\n";
	}

	void pause()
	{
		cout << description.c_str() << " paused \"" << title << "\"\n";
	}

	string toString()
	{
		return description;
	}
};
