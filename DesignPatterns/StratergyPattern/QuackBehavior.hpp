#pragma once
#include<iostream>
class QuackBehavior
{
public:
    virtual ~QuackBehavior() = default;
    virtual void quack() = 0;
};

class Quack :public QuackBehavior
{
    void quack()
    {
        printf("Duck can quack");
    }
};

class Squeak :public QuackBehavior
{
    void quack()
    {
        printf("Duck can Squeak");
    }
};

class MuteQuack :public QuackBehavior
{
    void quack()
    {
        printf("Muted Duck");
    }
};