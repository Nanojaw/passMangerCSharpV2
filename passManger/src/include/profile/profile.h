#pragma once

#include "../credential/credential.h"

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

    void create_profile();
};
