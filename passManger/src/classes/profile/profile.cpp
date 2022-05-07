#include "profile.h"
#include "../misc/misc.h"

#include <iostream>

int a = 0;

void profile::create_profile()
{
    if (a)
    {
        name = misc::prompt_user(L"Please fill out your full name");
        email = misc::prompt_user(L"Please fill out your preferred email");
    
        const std::wstring add_details = misc::prompt_user(L"Do you want to add any extra details about yourself? [Y]es, [N]o");

        switch (std::toupper(add_details[0]))
        {
        case 'Y':
            {
                bool running = true;

                while (running)
                {
                    std::wstring detail = misc::prompt_user(L"Provide the name of the detail");
                    std::wstring value = misc::prompt_user(L"Fill out the value");

                    extra_details.emplace_back(detail, value);

                    if (std::toupper(misc::prompt_user(L"More")[0]) == 'N') running = false;
                }
                break;
            }

        case 'N':
            {
                break;
            }
        default: ;
        }

        const std::wstring tmp_pass = misc::hash_masterpassword(misc::prompt_user(L"Please enter a strong master-password"));
        std::wstring tmp_pass2 = misc::hash_masterpassword(misc::prompt_user(L"Please re-enter master-password to confirm"));

        while (tmp_pass != tmp_pass2)
        {
            tmp_pass2 = misc::hash_masterpassword(misc::prompt_user(L"Re-enter master-password"));
        }

        master_password = tmp_pass2;
    
        const std::wstring add_credentials = misc::prompt_user(L"Do you want to add any credentials? [Y]es, [N]o");

        switch (std::toupper(add_credentials[0]))
        {
        case 'Y':
            {
                bool running = true;

                while (running)
                {
                    std::wstring c_name = misc::prompt_user(L"Enter name of the credential");
                    std::wstring c_site = misc::prompt_user(L"Enter site url");
    
                    std::wstring c_username = misc::prompt_user(L"Enter username");
                    std::wstring c_email = misc::prompt_user(L"Enter email");
                    std::wstring c_password = misc::prompt_user(L"Enter password");

                    credentials.emplace_back(c_name, c_site, c_username, c_email, c_password);
                
                    if (std::toupper(misc::prompt_user(L"More")[0]) == 'N') running = false;
                }
                break;
            }

        case 'N':
            {
                break;
            }
        default: ;
        }

        const std::wstring add_keys = misc::prompt_user(L"Do you want to add any keys? [Y]es, [N]o");

        switch (std::toupper(add_keys[0]))
        {
        case 'Y':
            {
                bool running = true;

                while (running)
                {
                    std::wstring key_name = misc::prompt_user(L"Enter the name of the key");
                    std::wstring url = misc::prompt_user(L"Enter the url that is using the key");

                    std::wstring key_str = misc::prompt_user(L"Enter the key");

                    keys.emplace_back(key_name, url, key_str);
                
                    if (std::toupper(misc::prompt_user(L"More")[0]) == 'N') running = false;
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

    name = L"Malte Axner";
    email = L"malteaxner@gmail.com";

    extra_details = {
        std::pair<std::wstring, std::wstring>(L"a", L"a"),
        std::pair<std::wstring, std::wstring>(L"b", L"b"),
        std::pair<std::wstring, std::wstring>(L"c", L"c"),
        std::pair<std::wstring, std::wstring>(L"d", L"d"),
        std::pair<std::wstring, std::wstring>(L"e", L"e"),
        std::pair<std::wstring, std::wstring>(L"f", L"f")
    };

    master_password = misc::hash_masterpassword(L"IsakIsBadLeLV2");

    credentials = {
        credential(L"test", L"test_site", L"test_username", L"test_email", L"test_password"),
        credential(L"test1", L"test_site1", L"test_username1", L"test_email1", L"test_password1"),
        credential(L"test2", L"test_site2", L"test_username2", L"test_email2", L"test_password2"),
        credential(L"test3", L"test_site3", L"test_username3", L"test_email3", L"test_password3"),
        credential(L"test4", L"test_site4", L"test_username4", L"test_email4", L"test_password4"),
        credential(L"test5", L"test_site5", L"test_username5", L"test_email5", L"test_password5")
    };

    keys = {
        key(L"test", L"test_site", L"test_key"),
        key(L"test1", L"test_site1", L"test_key1"),
        key(L"test2", L"test_site2", L"test_key2"),
        key(L"test3", L"test_site3", L"test_key3"),
        key(L"test4", L"test_site4", L"test_key4"),
        key(L"test5", L"test_site5", L"test_key5")
    };
    
    save_profile();
}

void profile::save_profile()
{
    std::wstring file_path = misc::prompt_user(L"Enter path where the file is going to be saved");

    
}
