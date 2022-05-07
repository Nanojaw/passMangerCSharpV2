#pragma once

#include "../credential/credential.h"
#include "../key/key.h"

#include <string>
#include <vector>

class profile
{
public:
    std::wstring name;
    std::wstring email;
    std::vector<std::pair<std::wstring, std::wstring>> extra_details;
    std::wstring master_password;
    std::vector<credential> credentials;

    std::vector<key> keys;

    void create_profile();
    void save_profile();
};
