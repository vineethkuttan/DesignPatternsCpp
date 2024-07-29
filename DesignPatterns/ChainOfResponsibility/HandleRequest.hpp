#pragma once
#include<iostream>
class HttpRequest {
private:
    std::string username;
    std::string password;

public:
    HttpRequest(std::string _username, std::string _password)
    {
        username = _username;
        password = _password;
    }
    std::string getUsername()
    {
        return username;
    }
    std::string getPassword()
    {
        return password;
    }
};