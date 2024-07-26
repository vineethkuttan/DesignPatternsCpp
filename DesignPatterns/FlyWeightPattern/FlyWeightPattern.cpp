#include "PointService.hpp"

int main()
{
    PointService service(std::make_shared<PointIconFactory>());
    for (auto point : service.getPoints())
    {
        point->draw();
    }
}