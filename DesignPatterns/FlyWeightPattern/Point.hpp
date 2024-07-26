#pragma once
#include "PointIcon.hpp"
#include<iostream>
class Point
{
private:
    int x;
    int y;
    std::shared_ptr<PointIcon> icon;
public:
    Point(int _x, int _y, std::shared_ptr<PointIcon> _icon)
    {
        x = _x;
        y = _y;
        icon = _icon;
    }

    void draw()
    {
        printf("%d at (%d, %d)", icon->getType(), x, y);
    }
};