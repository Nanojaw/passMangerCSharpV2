#include "../../include/credential/credential.h"

credential::credential(const std::string& n, const std::string& s, const std::string& u, const std::string& e, const std::string& p)
{
    name = n;
    site = s;
        
    username = u;
    email = e;
    password = p;
}
