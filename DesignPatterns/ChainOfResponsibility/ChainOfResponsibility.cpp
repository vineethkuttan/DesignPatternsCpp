#include "WebServer.hpp"
#include "Logger.hpp"
#include "Compressor.hpp"
#include "Authenticator.hpp"
#include "Encryptor.hpp"

int main()
{
    std::shared_ptr<Encryptor> encryptor = std::make_shared<Encryptor>(nullptr);
    std::shared_ptr<Compressor> compressor = std::make_shared<Compressor>(encryptor);
    std::shared_ptr<Logger> logger = std::make_shared<Logger>(compressor);
    std::shared_ptr<Authenticator> authenticator = std::make_shared<Authenticator>(logger);
    std::shared_ptr<WebServer> webServer = std::make_shared<WebServer>(authenticator);
    webServer->handle(std::make_shared<HttpRequest>("admin", "1234"));
}