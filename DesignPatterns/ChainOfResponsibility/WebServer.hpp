#pragma once
#include "Handler.hpp"
class WebServer {
private:
    std::shared_ptr<Handler> handler;
public:
    WebServer(std::shared_ptr<Handler> _handler)
    {
        handler = _handler;
    }

    void handle(std::shared_ptr<HttpRequest> _request)
    {
        handler->handle(_request);
    }
};