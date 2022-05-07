#pragma once
#include <string>

class key
{
public:
    std::string name;
    std::string site;
    std::string key_str;
    
    key(const std::string& key_name, const std::string& url, const std::string& key_string);
};
