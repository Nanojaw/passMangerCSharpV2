#pragma once
#include <iostream>
#include <string>
#include <vector>

inline bool exists (const std::string& name) {
    struct stat buffer{};   
    return (stat (name.c_str(), &buffer) == 0); 
}

inline std::string hash_string(std::string plain_text)
{
    return plain_text;
}

inline std::string prompt_user(const std::string& prompt)
{
    std::string result;
    std::cout << prompt + ": ";

    std::getline(std::cin, result);
    std::cout << std::endl;
        
    return result;
}

struct credential
{
    std::string name;
    std::string id;
    std::string site;
    std::string email;
    std::string password;
};

struct profile_info
{
    std::string name;
    std::string email;
    std::vector<std::pair<std::string, std::string>> extra_details;
    std::string master_password;
    std::vector<credential> credentials;
};

class application
{
    profile_info profile_;
    
public:
    explicit application(const std::string& file_path)
    {
        if (exists(file_path))
        {
            main_loop(false);
        }
        else
        {
            create_profile();
        }
    }

private:
    void main_loop(bool already_logged_in)
    {
        return;
    }

    void create_profile()
    {
        profile_.name = prompt_user("Please fill out your full name")[1];
        profile_.email = prompt_user("Please fill out your preferred email")[1];
        
        if (prompt_user("Do you want to add any extra details about yourself? [Y]es, [N]o") == "Y")
        {
            bool add_more = true;
            
            while (add_more)
            {
                std::string detail = prompt_user("Name the detail");
                std::string value = prompt_user("Provide a value for " + detail);

                profile_.extra_details.emplace_back(detail, value);

                if (prompt_user("DO you want to add more? [Y]es, [N]o") == "N")
                {
                    add_more = false;
                }
            }
        }

        const std::string temp_password = hash_string(prompt_user("Please fill out a strong master password"));
        std::string temp_password2 = hash_string(prompt_user("Please re-enter your master password for confirmation"));

        while (temp_password != temp_password2)
        {
            std::cout << "Error, the master passwords do not match. Please try again!" << std::endl;

            temp_password2 = hash_string(prompt_user("Please re-enter your master password"));
        }

        profile_.master_password = temp_password;

        if (prompt_user("Do you want to add some credentials? [Y]es, [N]o") == "Yes")
        {
            bool add_more = true;
        }
    }
};
