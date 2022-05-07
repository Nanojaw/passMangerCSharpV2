#pragma once
#include <string>
#include <vector>

class misc
{
public:
    static std::string prompt_user(std::string prompt);
    static std::string hash_masterpassword(const std::string& password);
    static std::vector<int> get_encryption_key(const std::string& password);
};
