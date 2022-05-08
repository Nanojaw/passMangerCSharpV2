#pragma once
#include <string>
#include <vector>
#include "../profile/profile.h"

class misc
{
public:
    static void add_cred_to_list(std::vector<credential>& creds, std::vector<std::wstring>& lines, int& index);
    static std::wstring prompt_user(const std::wstring&);
    static std::wstring hash_masterpassword(const std::wstring& password);
    static std::vector<int> get_encryption_key(const std::wstring& password);
    static std::wstring construct_pi(const profile& user);
    static std::wstring construct_cs(const profile& user);
    static std::wstring construct_ks(const profile& user);
    static void add_key_to_list(std::vector<key>& keys, std::vector<std::wstring>& lines, int& index);
};
