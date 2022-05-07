#include "../../include/profile/profile.h"
#include  "../../include/misc/misc.h"

#include <iostream>

void profile::create_profile()
{
    name = misc::prompt_user("Please fill out your full name");
    email = misc::prompt_user("Please fill out your preferred email");

    const std::string add_details = misc::prompt_user("Do you want to add any extra details about yourself? [Y]es, [N]o");

    switch (std::toupper(add_details[0]))
    {
    case 'Y':
        {
            bool running = true;

            while (running)
            {
                std::string detail = misc::prompt_user("Provide the name of the detail");
                std::string value = misc::prompt_user("Fill out the value");

                extra_details.emplace_back(detail, value);

                if (std::toupper(misc::prompt_user("More")[0]) == 'N') running = false;
            }
            break;
        }

    case 'N':
        {
            break;
        }
    default: ;
    }

    
}
