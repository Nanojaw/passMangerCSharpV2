#include "misc.h"

#include <iostream>
#include <random>

#include "../../../../hashingLib/src/sha1.h"
#include "../../../../hashingLib/src/sha2_224.h"
#include "../../../../hashingLib/src/sha2_256.h"
#include "../../../../hashingLib/src/sha2_512.h"
#include "../../../../hashingLib/src/sha2_384.h"

constexpr int encryptor_size = 16;

std::wstring misc::prompt_user(const std::wstring& prompt)
{
    std::wstring answer;
    
    std::wcout << prompt + L": ";
    std::getline(std::wcin, answer);
    std::cout << std::endl;

    return answer;
}

std::wstring misc::hash_masterpassword(const std::wstring& password)
{
    auto sha1 = Chocobo1::SHA1();
    auto sha224 = Chocobo1::SHA2_224();
    auto sha256 = Chocobo1::SHA2_256();
    auto sha512 = Chocobo1::SHA2_512();
    auto sha384 = Chocobo1::SHA2_384();

    const auto hash1 = sha1.addData(password.c_str(), password.length()).finalize().toString();
    const auto hash224 = sha224.addData(hash1.c_str(), hash1.length()).finalize().toString();
    const auto hash256 = sha256.addData(hash224.c_str(), hash224.length()).finalize().toString();
    const auto hash512 = sha512.addData(hash256.c_str(), hash256.length()).finalize().toString();
    const auto hash384 = sha384.addData(hash512.c_str(), hash512.length()).finalize().toString();

    return std::wstring(hash384.begin(), hash384.end());
}

std::vector<int> misc::get_encryption_key(const std::wstring& password)
{
    // Create base randomizer
    std::default_random_engine base_gen (password.length());
    const std::uniform_int_distribution base_dist (16, 32);

    // Create index randomizer
    std::default_random_engine index_gen (password.length());
    const std::uniform_int_distribution<int> index_dist (0, password.length() - 1);

    const int length = base_dist(base_gen);

    std::vector<int> result;
    result.reserve(length);

    for (int i = 0; i < length; i++)
    {
        std::default_random_engine generator (base_dist(base_gen) + password[index_dist(index_gen)]);
        std::uniform_int_distribution distribution(0, encryptor_size - 1);
        result.push_back(distribution(generator));
    }
    
    return result;
}

std::wstring misc::construct_pi(const profile& user)
{
    std::wstring result;

    result +=
        L"# Region Personal info #\n"
        "   Name: " + user.name + L"\n"
        "   Email: " + user.email + L"\n\n";

    result +=
        L"   # Subregion Extra details #\n";
    
    for (auto [first, second] : user.extra_details)
    {
        result +=
            L"      Detail: " + first + L" : " + second + L"\n";
    }

    result +=
        L"\n   # Subregion Master-password #\n"
        "       " + user.master_password;
    
    return result;
}

std::wstring misc::construct_cs(const profile& user)
{
    std::wstring result;

    result += L"\n# Region Credentials #\n";

    for (const auto& cred : user.credentials)
    {
        result +=
            L"  # Cred #\n"
            "       Name: " + cred.name + L"\n"
            "       Site: " + cred.site + L"\n"
        
            "       Username: " + cred.username + L"\n"
            "       Email: " + cred.email + L"\n"
            "       Password: " + cred.password + L"\n\n";
    }

    return result;
}

std::wstring misc::construct_ks(const profile& user)
{
    std::wstring result;

    result += L"# Region Keys #\n";

    for (const auto& key : user.keys)
    {
        result +=
            L"  # Key #\n"
            "       Name: " + key.name + L"\n"
            "       Site: " + key.site + L"\n"
        
            "       Key: " + key.key_str + L"\n\n";
    }

    result.resize(result.length() - 1);
    
    return result;
}
