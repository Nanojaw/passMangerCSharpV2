#pragma once
#include <string>

class credential
{
public:
    std::string name;
    std::string site;
    
    std::string username;
    std::string email;
    std::string password;

    credential(const std::string& n, const std::string& s, const std::string& u, const std::string& e, const std::string& p);
};
