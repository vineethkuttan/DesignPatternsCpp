#pragma once
#include "Amplifier.hpp"
class Tuner {
	string description;
	double frequency;

public:
	Tuner(string _description)
	{
		description = _description;
	}
	void on()
	{
		cout << description << " on\n";
	}
	void off()
	{
		cout << description << " off\n";
	}
	void setFrequency(double _frequency)
	{
		cout << description << " setting frequency to " << _frequency << "\n";
		frequency = _frequency;
	}
	void setAm()
	{
		cout << description << " setting AM mode\n";
	}
	void setFm()
	{
		cout << description << " setting FM mode\n";
	}
	string toString()
	{
		return description;
	}
};