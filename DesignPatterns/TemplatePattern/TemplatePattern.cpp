#include "Coffee.hpp"
#include "Tea.hpp"
#include<memory>
#define shared_ptr std::shared_ptr
#define cout std::cout

/*#include <iostream>
using namespace std;

class A {
public:
	virtual bool fun();
};

class B : public A {};

bool A::fun()
{
	if (dynamic_cast<B*>(this)) { // Corrected dynamic_cast syntax
		return true;
	}
	return false;
}

int main() {
	A* obj = new A(); // Corrected object creation
	cout << obj->fun(); // Corrected function call
	delete obj; // Clean up memory
	return 0;
}*/

int main()
{
	shared_ptr<CaffeineBeverage> tea(new Tea());
	shared_ptr<CaffeineBeverage> coffee(new Coffee());

	printf("\nMaking tea...\n");
	tea->prepareRecipe();

	printf("\nMaking coffee...\n");
	coffee->prepareRecipe();


	shared_ptr<CaffeineBeverageWithHook> teaHook(new TeaWithHook());
	shared_ptr<CaffeineBeverageWithHook> coffeeHook = std::make_shared<CoffeeWithHook>();

	printf("\nMaking tea...\n");
	teaHook->prepareRecipe();

	printf("\nMaking coffee...\n");
	coffeeHook->prepareRecipe();
}