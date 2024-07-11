#pragma once
#include "Pizza.hpp"
class PizzaStore 
{
public:
	virtual ~PizzaStore() = default;
	virtual shared_ptr<Pizza> createPizza(string item)= 0;

	shared_ptr<Pizza> orderPizza(string type)
	{
		shared_ptr<Pizza> pizza = createPizza(type);
		printf("--- Making a %s --------\n" , pizza->getName().c_str());
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	}
};

class NYPizzaStore :public PizzaStore
{
public:
	NYPizzaStore() {
		// Initialize any member variables or perform setup here if needed
	}
	shared_ptr<Pizza> createPizza(string item) override
	{
		if (item.compare("cheese") == 0) 
		{
			return std::make_shared<NYStyleCheesePizza>();
		}
		else if (item.compare("veggie") == 0)
		{
			return std::make_shared<NYStyleVeggiePizza>();
		}
		else if (item.compare("clam") == 0)
		{
			return std::make_shared<NYStyleClamPizza>();
		}
		else if (item.compare("pepperoni") == 0)
		{
			return std::make_shared<NYStylePepperoniPizza>();
		}
		else
			return nullptr;
	}
};


class ChicagoPizzaStore :public PizzaStore
{
public:
	shared_ptr<Pizza> createPizza(string item)
	{
		if (item.compare("cheese")==0)
		{
			return std::make_shared<ChicagoStyleCheesePizza>();
		}
		else if (item.compare("veggie") == 0)
		{
			return std::make_shared<ChicagoStyleVeggiePizza>();
		}
		else if (item.compare("clam")==0)
		{
			return std::make_shared<ChicagoStyleClamPizza>();
		}
		else if (item.compare("pepperoni")==0)
		{
			return std::make_shared<ChicagoStylePepperoniPizza>();
		}
		else
			return nullptr;
	}
};

//class DependentPizzaStore {
//
//public:
//	shared_ptr<Pizza> createPizza(string style, string type) {
//		shared_ptr<Pizza> pizza = nullptr;
//		if (!style.compare("NY")) {
//			if (!type.compare("cheese")) {
//				pizza = std::make_shared<Pizza>(new NYStyleCheesePizza());
//			}
//			else if (!type.compare("veggie")) {
//				pizza = std::make_shared<Pizza>(new NYStyleVeggiePizza());
//			}
//			else if (!type.compare("clam")) {
//				pizza = std::make_shared<Pizza>(new NYStyleClamPizza());
//			}
//			else if (!type.compare("pepperoni")) {
//				pizza = std::make_shared<Pizza>(new NYStylePepperoniPizza());
//			}
//		}
//		else if (!style.compare("Chicago")) {
//			if (!type.compare("cheese")) {
//				pizza = std::make_shared<Pizza>(new ChicagoStyleCheesePizza());
//			}
//			else if (!type.compare("veggie")) {
//				pizza = std::make_shared<Pizza>(new ChicagoStyleVeggiePizza());
//			}
//			else if (!type.compare("clam")) {
//				pizza = std::make_shared<Pizza>(new ChicagoStyleClamPizza());
//			}
//			else if (!type.compare("pepperoni")) {
//				pizza = std::make_shared<Pizza>(new ChicagoStylePepperoniPizza());
//			}
//		}
//		else {
//			printf("Error: invalid type of pizza\n");
//			return nullptr;
//		}
//		pizza->prepare();
//		pizza->bake();
//		pizza->cut();
//		pizza->box();
//		return pizza;
//	}
//};
