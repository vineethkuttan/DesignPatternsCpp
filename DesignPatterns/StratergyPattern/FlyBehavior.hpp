#pragma once
#include<iostream>
class FlyBehavior
{
public:
    virtual ~FlyBehavior() = default;
    virtual void fly()= 0;
};

class FlyWithWings :public FlyBehavior
{
    void fly()
    {
        printf("Duck is flying with wings");
    }
};

class FlyNoWay :public FlyBehavior
{
    void fly()
    {
        printf("Duck can't fly");
    }
};