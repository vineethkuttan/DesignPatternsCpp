#pragma once
enum PointType { HOSPITAL,CAFE,RESTAURANT };
class PointIcon {
private:
    PointType type;
    char icon;    // 20 KB -> 20 MB

public:
    PointIcon(PointType _type, char _icon)
    {
        type = _type;
        icon = _icon;
    }

    PointType getType() {
        return type;
    }
};