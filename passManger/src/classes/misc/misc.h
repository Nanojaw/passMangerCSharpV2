#pragma once
#include <string>
#include <vector>
#include "../profile/profile.h"

class misc
{
public:
    static std::wstring prompt_user(const std::wstring&);
    static std::wstring hash_masterpassword(const std::wstring& password);
    static std::vector<int> get_encryption_key(const std::wstring& password);
    static std::wstring construct_pi(const profile& user);
    static std::wstring construct_cs(const profile& user);
    static std::wstring construct_ks(const profile& user);
};
