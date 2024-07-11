// FactoryPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PizzaStore.hpp"

/*
Inspired Sample
// Abstract product (Shape)
class Shape {
public:
    virtual ~Shape() = default;
    virtual string getName() const = 0;
};

// Concrete products (Circle and Square)
class Circle : public Shape {
public:
    string getName() const override {
        return "Circle";
    }
};

class Square : public Shape {
public:
    string getName() const override {
        return "Square";
    }
};

// Abstract factory (ShapeFactory)
class ShapeFactory {
public:
    virtual ~ShapeFactory() = default;
    virtual shared_ptr<Shape> createShape() = 0;
};

// Concrete factory (ConcreteShapeFactory)
class ConcreteShapeFactory : public ShapeFactory {
public:
    shared_ptr<Shape> createShape() override {
        // Decide which shape to create (e.g., based on user input or logic)
        // For simplicity, always create a Circle here
        return std::make_shared<Circle>();
    }
};
*/

int main() {
	unique_ptr<PizzaStore> nyStore = std::make_unique<NYPizzaStore>();
    unique_ptr<PizzaStore> chicagoStore = std::make_unique<ChicagoPizzaStore>();    
	shared_ptr<Pizza> pizza = nyStore->orderPizza("cheese");
	printf("Ethan ordered a %s \n",pizza->getName().c_str());
	printf("------------------------------------------------------------------\n");
	pizza = chicagoStore->orderPizza("cheese");
	printf("Joel ordered a %s \n", pizza->getName().c_str());
	printf("------------------------------------------------------------------\n");
	pizza = nyStore->orderPizza("clam");
	printf("Ethan ordered a %s \n", pizza->getName().c_str());
	printf("------------------------------------------------------------------\n");
	pizza = chicagoStore->orderPizza("clam");
	printf("Joel ordered a %s \n", pizza->getName().c_str());
	printf("------------------------------------------------------------------\n");
	pizza = nyStore->orderPizza("pepperoni");
	printf("Ethan ordered a %s \n", pizza->getName().c_str());
	printf("------------------------------------------------------------------\n");
	pizza = chicagoStore->orderPizza("pepperoni");
	printf("Joel ordered a %s \n", pizza->getName().c_str());
	printf("------------------------------------------------------------------\n");
	pizza = nyStore->orderPizza("veggie");
	printf("Ethan ordered a %s \n", pizza->getName().c_str());
	printf("------------------------------------------------------------------\n");
	pizza = chicagoStore->orderPizza("veggie");
	printf("Joel ordered a %s \n", pizza->getName().c_str());
	printf("------------------------------------------------------------------\n");
    return 0;
}
