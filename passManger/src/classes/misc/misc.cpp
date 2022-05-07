#include "misc.h"

#include <iostream>

#include "../../libs/sha256.h"

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
    return sha256(password);
}
