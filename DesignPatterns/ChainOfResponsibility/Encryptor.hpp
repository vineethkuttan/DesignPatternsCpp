#pragma once
#include "Handler.hpp"
class Encryptor :public Handler
{
public:
    Encryptor(std::shared_ptr<Handler> next) :Handler(next)
    {
    }

    bool doHandle(std::shared_ptr<HttpRequest> request) override
    {
        printf("Encryption\n");
        return false;
    }
};