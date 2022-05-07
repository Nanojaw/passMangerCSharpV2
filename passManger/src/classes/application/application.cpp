#include "application.h"

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
                /*login();*/
                break;
            }
        case 'E':
            {
                running = false;
                /*save_profile();*/
                break;
            }
            default: ;
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
        }
    }
}
