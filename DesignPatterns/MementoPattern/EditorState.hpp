#pragma once
#include<iostream>
class EditorState
{
private:
	std::string content;
public:
	EditorState(std::string cont)
	{
		content = cont;
	}
	std::string getContent()
	{
		return content;
	}
};
