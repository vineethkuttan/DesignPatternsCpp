#pragma once
#include "EditorState.hpp"
class Editor
{
public:
	std::string content;
	EditorState CreateState()
	{
		return EditorState(content);
	}
	void restore(EditorState ES)
	{
		content = ES.getContent();
	}
	std::string getCurrContent()
	{
		return content;
	}
};