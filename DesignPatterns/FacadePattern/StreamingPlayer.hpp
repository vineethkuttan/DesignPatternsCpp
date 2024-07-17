#pragma once
#include "TheaterLights.hpp"
class StreamingPlayer
{
private:
	string description;
	int currentChapter;
	string movie;

public:
	StreamingPlayer(string _description)
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

	void play(string& _movie)
	{
		movie = _movie;
		currentChapter = 0;
		cout << description.c_str() << " playing \"" << movie.c_str() << "\"\n";
	}


	void play(int chapter)
	{
		if (movie == "")
		{
			cout << description.c_str() << " can't play chapter " << chapter << " no movie selected\n";
		}
		else
		{
			currentChapter = chapter;
			cout << description.c_str() << " playing chapter " << currentChapter << " of \"" << movie.c_str() << "\"\n";
		}
	}

	void stop()
	{
		currentChapter = 0;
		cout << description.c_str() << " stopped \"" << movie.c_str() << "\"\n";
	}

	void pause()
	{
		cout << description.c_str() << " paused \"" << movie.c_str() << "\"\n";
	}
	void setTwoChannelAudio()
	{
		cout << description.c_str() << " set two channel audio\n";
	}
	void setSurroundAudio()
	{
		cout << description.c_str() << " set surround audio\n";
	}
	string toString() 
	{
		return description;
	}
};
