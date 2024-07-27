#pragma once
#include "Component.hpp"
class Circle :public Component
{
public:
	int radius;
	Circle(int radius)
		: radius(radius)
	{
	}
	void render() override
	{
		printf("Rendering Circle\n");
	}
	std::shared_ptr<Component> clone() override
	{
		return std::make_shared<Circle>(radius);

	}	
};