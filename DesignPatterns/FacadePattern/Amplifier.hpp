#pragma once
#include "StreamingPlayer.hpp"
#include "Tuner.hpp"
class Amplifier
{
private:
	string description;
	shared_ptr<Tuner> tuner;
	shared_ptr<StreamingPlayer> player;

public:
	Amplifier(string _description)
	{
		description = _description;
	}
	void on()
	{
		cout << description.c_str() << " on\n";
	}
	void off()
	{
		cout << description.c_str() << " off\n";
	}
	void setStereoSound()
	{
		cout << description.c_str() << " stereo mode on";
	}
	void setSurroundSound()
	{
		cout << description.c_str() << " surround sound on (5 speakers, 1 subwoofer)\n";
	}
	void setVolume(int level)
	{
		cout << description.c_str() << " setting volume to " << level << "\n";
	}
	void setTuner(shared_ptr<Tuner>& _tuner)
	{
		cout << description.c_str() << " setting tuner to " << _tuner;
		tuner = _tuner;
	}

	void setStreamingPlayer(shared_ptr<StreamingPlayer>& _player)
	{
		cout << description.c_str() << " setting Streaming player to " << _player->toString() << "\n";
		player = _player;
	}

	string toString()
	{
		return description;
	}
};