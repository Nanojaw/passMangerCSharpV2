#include "key.h"

key::key(const std::string& key_name, const std::string& url, const std::string& key_string)
{
    name = key_name;
    site = url;
    key_str = key_string;
}
