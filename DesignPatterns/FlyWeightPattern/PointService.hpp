#pragma once
#include "PointIconFactory.hpp"
#include<list>
class PointService
{
private:
    std::shared_ptr<PointIconFactory> iconFactory;

public:
    PointService(std::shared_ptr<PointIconFactory> _iconFactory)
    {
        iconFactory = _iconFactory;
    }

    std::list< std::shared_ptr<Point>> getPoints()
    {
        std::list<std::shared_ptr<Point>> points;
        std::shared_ptr<Point> point = std::make_shared<Point>(1, 2, iconFactory->getPointIcon(PointType::CAFE));
        points.emplace_back(point);
        return points;
    }
};