#pragma once
#include "Component.hpp"
class ContextMenu
{
public:
	std::shared_ptr<Component> duplicate(std::shared_ptr<Component> obj)
	{
		return obj->clone();
	}
};