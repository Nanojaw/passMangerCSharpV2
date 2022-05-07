#pragma once
#include <string>
#include <vector>

class misc
{
public:
    static std::wstring prompt_user(std::wstring prompt);
    static std::wstring hash_masterpassword(const std::wstring& password);
    static std::vector<int> get_encryption_key(const std::string& password);
};
