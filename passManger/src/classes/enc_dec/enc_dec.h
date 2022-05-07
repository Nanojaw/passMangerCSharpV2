#pragma once
#include <string>
#include <vector>

class encrypter_decrypter
{
public:
    static void encrypt_string(std::wstring& str, const std::vector<int>& key);
    static void decrypt_string(std::wstring& str, std::vector<int>& key);
};
