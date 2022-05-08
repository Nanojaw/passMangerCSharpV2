#include "application.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

void application::run()
{
    std::cout <<
        "########################################################################\n"
        "#  Welcome to passManger, an application to help you manage passwords  #\n"
        "#               Type H to se what options are available                #\n"
        "########################################################################\n"
    << std::endl;

    bool running = true;
        
    while (running)
    {
        std::wstring option;

        std::getline(std::wcin, option);

        switch (std::toupper(option[0]))
        {
        case 'C':
            {
                user.create_profile();
                break;
            }
        case 'L':
            {
                user.create_profile();
                login();
                break;
            }
        case 'E':
            {
                running = false;
                user.save_profile();
                break;
            }
        case 'H': 
            {
                std::cout << 
                    "########################################################################\n"
                    "#               Welcome to the help page for passManger!               #\n"
                    "#     Below is a list of available options and their descriptions:     #\n"
                    "# C : Create a new profile                                             #\n"
                    "# L : Log in to existing profile                                       #\n"
                    "# E : Save changes and exit the password manager                       #\n"
                    "# H : Display this message                                             #\n"
                    "########################################################################\n"
                << std::endl;
                break;
            }   
            default: ;
        }
    }
}

void application::login()
{
    auto file = std::wifstream(std::filesystem::current_path() / "profileFile.txt");

    std::wstring line;
    std::vector<std::wstring> lines;
    
    while (std::getline(file, line)) lines.push_back(line);

    file.close();
    
    // Start of parser

    user.name = lines[1].substr(9);
    user.email = lines[2].substr(10);

    int index = 5;
    while (!lines[index].empty())
    {
        auto trimmed_string = lines[index].substr(14);
        
        user.extra_details.emplace_back(trimmed_string.substr(0, trimmed_string.length() - trimmed_string.find(':') - 2), trimmed_string.substr(trimmed_string.find(':') + 2));
        
        index++;
    }

    index++;
    index++;

    user.master_password = lines[index].substr(7);

    index++;
    index++;
    index++;

    while (!lines[index].empty())
    {
        auto trimmed_string = lines[index].substr(7);

        std::wcout << lines[index];
        
        index++;
    }
}
