#pragma once

#include "../credential/credential.h"
#include "../key/key.h"

#include <string>
#include <vector>

class profile
{
public:
    std::string name;
    std::string email;
    std::vector<std::pair<std::string, std::string>> extra_details;
    std::string master_password;
    std::vector<credential> credentials;

    std::vector<key> keys;

    void create_profile();
    void save_profile();
};
