#pragma once
#include "Handler.hpp"
class Logger :public Handler
{
public:
    Logger(std::shared_ptr<Handler> next) :Handler(next)
    {
    }

    bool doHandle(std::shared_ptr<HttpRequest> request)  override
    {
        printf("Log\n");
        return false;
    }
};