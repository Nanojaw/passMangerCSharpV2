#include "misc.h"

#include <iostream>
#include <random>

#include "msclr/marshal.h"
#include "msclr/marshal_cppstd.h"

constexpr int encryptor_size = 16;

std::wstring misc::prompt_user(const std::wstring prompt)
{
    std::wstring answer;
    
    std::wcout << prompt + L": ";
    std::getline(std::wcin, answer);
    std::cout << std::endl;

    return answer;
}

std::wstring misc::hash_masterpassword(const std::wstring& password)
{
    if (password.empty()) return password;
    
    auto sha1 = gcnew System::Security::Cryptography::SHA1Managed();
    auto sha256 = gcnew System::Security::Cryptography::SHA256Managed();
    auto sha384 = gcnew System::Security::Cryptography::SHA384Managed();
    auto sha512 = gcnew System::Security::Cryptography::SHA512Managed();

    array<wchar_t>^ pass_wc_array = {};

    System::Array::Resize(pass_wc_array, password.length());

    for (int i = 0; i < password.length() - 1; ++i)
    {
        pass_wc_array[i] = password[i];
    }

    auto text_bytes = System::Text::Encoding::UTF8->GetBytes(pass_wc_array);
    auto hash1 = sha1->ComputeHash(text_bytes);
    auto hash256 = sha1->ComputeHash(hash1);
    auto hash384 = sha1->ComputeHash(hash256);
    auto hash512 = sha1->ComputeHash(hash384);

    auto s_str = System::BitConverter::ToString(hash512);
    
    return msclr::interop::marshal_as<std::wstring>(s_str);
}

std::vector<int> misc::get_encryption_key(const std::string& password)
{
    // Create base randomizer
    std::default_random_engine baseGen (password.length());
    std::uniform_int_distribution<char> baseDist (16, 32);

    // Create index randomizer
    std::default_random_engine indexGen (password.length());
    std::uniform_int_distribution<char> indexDist (0, password.length() - 1);

    int length = baseDist(baseGen);

    std::vector<int> result;
    result.reserve(length);

    for (int i = 0; i < length; i++)
    {
        std::default_random_engine generator (baseDist(baseGen) + password[indexDist(indexGen)]);
        std::uniform_int_distribution<char> distribution(0, encryptor_size - 1);
        result.push_back(distribution(generator));
    }
    
    return result;
}
