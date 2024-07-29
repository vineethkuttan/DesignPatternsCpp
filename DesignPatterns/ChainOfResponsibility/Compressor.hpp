#pragma once
#include "Handler.hpp"
class Compressor :public Handler
{
public:
    Compressor(std::shared_ptr<Handler> next) :Handler(next)
    {
    }

    bool doHandle(std::shared_ptr<HttpRequest> request) override
    {
        printf("Compress\n");
        return false;
    }
};