#pragma once
#include<iostream>
class Slide
{
private:
	std::string text;
public:
	Slide(std::string _text)
	{
		text = _text;
	}
	std::string getText()
	{
		return text;
	}
	void setText(std::string _text)
	{
		text = _text;
	}
};