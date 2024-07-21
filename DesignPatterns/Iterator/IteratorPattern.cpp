#include "Waitress.hpp"
int main()
{
	std::shared_ptr<Menu> pancakeHouseMenu(new PancakeHouseMenu());
	std::shared_ptr<Menu> dinerMenu (new DinerMenu());
	Waitress waitress(pancakeHouseMenu, dinerMenu);
	waitress.printMenu();
	waitress.printVegetarianMenu();
}
