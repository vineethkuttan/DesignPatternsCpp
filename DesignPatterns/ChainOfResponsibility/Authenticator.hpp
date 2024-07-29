#pragma once
#include "Handler.hpp"
class Authenticator :public Handler
{
public:
    Authenticator(std::shared_ptr<Handler> next) :Handler(next)
    {
    }
    bool doHandle(std::shared_ptr<HttpRequest> request) override
    {
        bool isValid = (request->getUsername() == "admin" &&
                        request->getPassword() == "1234");
        printf("Authentication\n");
        return !isValid;
    }
};
