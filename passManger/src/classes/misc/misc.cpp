#include "misc.h"

#include <iostream>
#include <random>

#include "../../libs/sha256.h"

constexpr int encryptor_size = 16;

std::string misc::prompt_user(const std::string prompt)
{
    std::string answer;
    
    std::cout << prompt + ": ";
    std::getline(std::cin, answer);
    std::cout << std::endl;

    return answer;
}

std::string misc::hash_masterpassword(const std::string& password)
{
    return sha256(password);
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
