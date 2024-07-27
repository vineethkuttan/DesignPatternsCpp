#include"ContextMenu.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include <iostream>

int main()
{
	std::shared_ptr<Component> circle(new Circle(5));
	circle->render();
	ContextMenu cm;
	std::shared_ptr<Component> Newcircle = cm.duplicate(circle);
	Newcircle->render();
	std::shared_ptr<Component> square(new Square(5));
	square->render();
	std::shared_ptr<Component> Newsquare = cm.duplicate(square);
	square->render();
}