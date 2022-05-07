#pragma once
#include <string>

class credential
{
public:
    std::wstring name;
    std::wstring site;
    
    std::wstring username;
    std::wstring email;
    std::wstring password;

    credential(const std::wstring& n, const std::wstring& s, const std::wstring& u, const std::wstring& e, const std::wstring& p);
};
