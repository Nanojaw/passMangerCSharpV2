#include "key.h"

key::key(const std::wstring& key_name, const std::wstring& url, const std::wstring& key_string)
{
    name = key_name;
    site = url;
    key_str = key_string;
}
