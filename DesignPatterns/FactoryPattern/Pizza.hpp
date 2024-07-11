#pragma once
#include<iostream>
#include<memory>
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
#define string std::string

class Pizza {
public:
	string name;
	string dough;
	string sauce;

	void prepare() {
		printf("Prepare %s\n",name.c_str());
		printf("Tossing dough...\n");
		printf("Adding sauce...\n");
	}

	void bake() {
		printf("Bake for 25 minutes at 350\n");
	}

	void cut() {
		printf("Cut the pizza into diagonal slices\n");
	}

	void box() {
		printf("Place pizza in official PizzaStore box\n");
	}

	string getName() {
		return name;
	}

	string toString() {
		string display ;
		display.append("---- " + name + " ----\n");
		display.append(dough + "\n");
		display.append(sauce + "\n");
		return display;
	}
};

class ChicagoStyleCheesePizza :public Pizza 
{
public:
	ChicagoStyleCheesePizza() {
		name = "Chicago Style Deep Dish Cheese Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";
	}

	void cut() {
		printf("Cutting the pizza into square slices\n");
	}
};

class NYStyleCheesePizza :public Pizza 
{
public:
	NYStyleCheesePizza() {
		name = "NY Style Sauce and Cheese Pizza";
		dough = "Thin Crust Dough";
		sauce = "Marinara Sauce";
	}
};

class ChicagoStyleClamPizza :public Pizza 
{
public:
	ChicagoStyleClamPizza() {
		name = "Chicago Style Clam Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";
	}

	void cut() {
		printf("Cutting the pizza into square slices\n");
	}
};

class ChicagoStylePepperoniPizza :public Pizza 
{
public:
	ChicagoStylePepperoniPizza() {
		name = "Chicago Style Pepperoni Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";
	}

	void cut() {
		printf("Cutting the pizza into square slices\n");
	}
};

class ChicagoStyleVeggiePizza :public Pizza {
public:
	ChicagoStyleVeggiePizza() {
		name = "Chicago Deep Dish Veggie Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";
	}

	void cut() {
		printf("Cutting the pizza into square slices\n");
	}
};


class NYStyleClamPizza :public Pizza 
{
public:
	NYStyleClamPizza() {
		name = "NY Style Clam Pizza";
		dough = "Thin Crust Dough";
		sauce = "Marinara Sauce";
	}
};

class NYStylePepperoniPizza :public Pizza {

public :
	NYStylePepperoniPizza() {
		name = "NY Style Pepperoni Pizza";
		dough = "Thin Crust Dough";
		sauce = "Marinara Sauce";

	}
};

class NYStyleVeggiePizza :public Pizza 
{

public:
	NYStyleVeggiePizza() {
		name = "NY Style Veggie Pizza";
		dough = "Thin Crust Dough";
		sauce = "Marinara Sauce";
	}
};