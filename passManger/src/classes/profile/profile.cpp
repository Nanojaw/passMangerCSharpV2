#include "profile.h"
#include "../misc/misc.h"

#include <iostream>

int a = 0;

void profile::create_profile()
{
    if (a)
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

        const std::string tmp_pass = misc::hash_masterpassword(misc::prompt_user("Please enter a strong master-password"));
        std::string tmp_pass2 = misc::hash_masterpassword(misc::prompt_user("Please re-enter master-password to confirm"));

        while (tmp_pass != tmp_pass2)
        {
            tmp_pass2 = misc::hash_masterpassword(misc::prompt_user("Re-enter master-password"));
        }

        master_password = tmp_pass2;
    
        const std::string add_credentials = misc::prompt_user("Do you want to add any credentials? [Y]es, [N]o");

        switch (std::toupper(add_credentials[0]))
        {
        case 'Y':
            {
                bool running = true;

                while (running)
                {
                    std::string c_name = misc::prompt_user("Enter name of the credential");
                    std::string c_site = misc::prompt_user("Enter site url");
    
                    std::string c_username = misc::prompt_user("Enter username");
                    std::string c_email = misc::prompt_user("Enter email");
                    std::string c_password = misc::prompt_user("Enter password");

                    credentials.emplace_back(c_name, c_site, c_username, c_email, c_password);
                
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

        const std::string add_keys = misc::prompt_user("Do you want to add any keys? [Y]es, [N]o");

        switch (std::toupper(add_keys[0]))
        {
        case 'Y':
            {
                bool running = true;

                while (running)
                {
                    std::string key_name = misc::prompt_user("Enter the name of the key");
                    std::string url = misc::prompt_user("Enter the url that is using the key");

                    std::string key_str = misc::prompt_user("Enter the key");

                    keys.emplace_back(key_name, url, key_str);
                
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

    name = "Malte Axner";
    email = "malteaxner@gmail.com";

    extra_details = {
        std::pair<std::string, std::string>("a", "a"),
        std::pair<std::string, std::string>("b", "b"),
        std::pair<std::string, std::string>("c", "c"),
        std::pair<std::string, std::string>("d", "d"),
        std::pair<std::string, std::string>("e", "e"),
        std::pair<std::string, std::string>("f", "f")
    };

    master_password = misc::hash_masterpassword("IsakIsBadLeLV2");

    credentials = {
        credential("test", "test_site", "test_username", "test_email", "test_password"),
        credential("test1", "test_site1", "test_username1", "test_email1", "test_password1"),
        credential("test2", "test_site2", "test_username2", "test_email2", "test_password2"),
        credential("test3", "test_site3", "test_username3", "test_email3", "test_password3"),
        credential("test4", "test_site4", "test_username4", "test_email4", "test_password4"),
        credential("test5", "test_site5", "test_username5", "test_email5", "test_password5")
    };

    keys = {
        key("test", "test_site", "test_key"),
        key("test1", "test_site1", "test_key1"),
        key("test2", "test_site2", "test_key2"),
        key("test3", "test_site3", "test_key3"),
        key("test4", "test_site4", "test_key4"),
        key("test5", "test_site5", "test_key5")
    };
    
    save_profile();
}

void profile::save_profile()
{
    std::string file_path = misc::prompt_user("Enter path where the file is going to be saved");

    
}
