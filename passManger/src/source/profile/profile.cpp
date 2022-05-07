#include "../../include/profile/profile.h"
#include  "../../include/misc/misc.h"

#include <iostream>

void profile::create_profile()
{
    name = misc::prompt_user("Please fill out your full name");
    email = misc::prompt_user("Please fill out your preferred email");
}
