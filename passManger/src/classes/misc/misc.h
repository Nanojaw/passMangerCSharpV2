#pragma once
#include <string>

class misc
{
public:
    static std::wstring prompt_user(std::wstring prompt);
    static std::wstring hash_masterpassword(const std::wstring& password);
};
