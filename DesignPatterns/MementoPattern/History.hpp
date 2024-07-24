#pragma once
#include"EditorState.hpp"
#include<stack>
class History
{
private:
	std::stack<EditorState> History;
public:
	void pushState(EditorState es)
	{
		History.push(es);
	}
	EditorState popState()
	{
		History.pop();
		return History.top();
	}
};