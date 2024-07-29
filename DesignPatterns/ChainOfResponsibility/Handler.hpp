#pragma once
#include "HandleRequest.hpp"
class Handler
{
private:
    std::shared_ptr<Handler> next;

public:
    Handler(std::shared_ptr<Handler> _next)
    {
        next = _next;
    }
    void handle(std::shared_ptr<HttpRequest> request)
    {
        if (doHandle(request))
            return;

        if (next != nullptr)
            next->handle(request);
    }
    virtual bool doHandle(std::shared_ptr<HttpRequest> request) = 0;
};