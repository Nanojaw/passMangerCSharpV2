#pragma once
#include <iostream>
#include <string>

inline bool exists (const std::string& name) {
    struct stat buffer{};   
    return (stat (name.c_str(), &buffer) == 0); 
}

struct profile_info
{
    std::string name;
    std::string encrypted_name;

    std::string email;
    std::string encrypted_email;
    
    std::string master_password;
    std::string encrypted_master_password;

    
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
        std::cout << "Please enter your name: " << std::endl;
        std::getline(std::cin, profile_.name);

        std::cout << "Please enter your email: " << std::endl;
        std::getline(std::cin, profile_.email);
        
        std::cout << "Please enter a secure master password: " << std::endl;
        std::getline(std::cin, profile_.master_password);
    }
};
