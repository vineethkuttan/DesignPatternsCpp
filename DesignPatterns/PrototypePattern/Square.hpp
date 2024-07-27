#pragma once
#include "Component.hpp"
class Square :public Component
{
public:
	int side;

	Square(int side)
		: side(side)
	{
	}
	void render() override
	{
		printf("Rendering Square\n");
	}
	std::shared_ptr<Component> clone() override
	{
		return std::make_shared<Square>(side);
	}
};