#pragma once
#include <string>
#include <vector>

class misc
{
public:
    static std::string prompt_user(std::wstring prompt);
    static std::string hash_masterpassword(const std::wstring& password);
    static std::vector<int> get_encryption_key(const std::string& password);
};
