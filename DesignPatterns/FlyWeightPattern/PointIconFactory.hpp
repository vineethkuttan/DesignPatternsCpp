#pragma once
#include "Point.hpp"
#include<unordered_map>
class PointIconFactory
{
private:
    std::unordered_map<PointType, std::shared_ptr<PointIcon>> icons;
public:
    std::shared_ptr<PointIcon> getPointIcon(PointType type)
    {
        if (icons.find(type) == icons.end())
        {
            std::shared_ptr<PointIcon> icon=std::make_shared<PointIcon>(type, '1');
            icons[type] = icon;
        }
        return icons[type];
    }
};
