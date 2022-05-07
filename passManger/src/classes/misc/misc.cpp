#include "misc.h"

#include <iostream>

#include "../../libs/sha256.h"

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
