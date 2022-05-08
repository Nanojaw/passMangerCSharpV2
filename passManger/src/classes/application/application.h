#pragma once
#include "../profile/profile.h"

class application
{
public:
    profile user;
    bool user_exists = false;
    void run();
    void login();
};
