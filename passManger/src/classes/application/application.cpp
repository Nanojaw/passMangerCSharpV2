#include "application.h"

#include <iostream>
#include <string>

void application::run()
{
    std::cout <<
        "########################################################################\n"
        "#  Welcome to passManger, an application to help you manage passwords  #\n"
        "#              Type help to se what options are available              #\n"
        "########################################################################"
    << std::endl;

    bool running = true;
        
    while (running)
    {
        std::string option;

        std::getline(std::cin, option);

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
        }
    }
}
