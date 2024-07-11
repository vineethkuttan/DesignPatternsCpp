#include "Duck.hpp"
#include <iostream>

int main()
{
    std::unique_ptr<Duck> DuckMallard = std::make_unique<MallardDuck>();
    if (DuckMallard != nullptr)
    {
        DuckMallard->display();
        DuckMallard->performFly();
        DuckMallard->performQuack();
    }
}
