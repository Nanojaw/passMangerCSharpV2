#pragma once
#include <string>

class key
{
public:
    std::wstring name;
    std::wstring site;
    std::wstring key_str;
    
    key(const std::wstring& key_name, const std::wstring& url, const std::wstring& key_string);
};
