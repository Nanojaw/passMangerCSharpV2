#include "../../include/misc/misc.h"

#include <iostream>

std::string misc::prompt_user(const std::string prompt)
{
    std::string answer;
    
    std::cout << prompt + ": ";
    std::getline(std::cin, answer);
    std::cout << std::endl;

    return answer;
}
