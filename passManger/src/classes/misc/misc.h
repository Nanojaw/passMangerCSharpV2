#pragma once
#include <string>

class misc
{
public:
    static std::string prompt_user(std::string prompt);
    static std::string hash_masterpassword(const std::string& password);
};
