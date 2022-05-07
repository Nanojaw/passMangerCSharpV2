#include "credential.h"

credential::credential(const std::wstring& n, const std::wstring& s, const std::wstring& u, const std::wstring& e, const std::wstring& p)
{
    name = n;
    site = s;
        
    username = u;
    email = e;
    password = p;
}
