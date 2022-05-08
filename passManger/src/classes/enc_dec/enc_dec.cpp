#include "enc_dec.h"

#include <algorithm>

#pragma region enc_funcs

void addOne(std::wstring& str )
{
    for (auto& c : str) c++;
}

#pragma endregion

#pragma region dec_funcs

void removeOne(std::wstring& str)
{
    for (auto& c : str) c--;
}

#pragma endregion


void encrypter_decrypter::encrypt_string(std::wstring& str, const std::vector<int>& key)
{
    for (auto i : key)
    {
        switch (i)
        {
        case 0:
            addOne(str);
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
            
        default: ;
        }
    }
}

void encrypter_decrypter::decrypt_string(std::wstring& str, std::vector<int>& key)
{
    std::reverse(key.begin(), key.end());
    
    for (auto i : key)
    {
        switch (i)
        {
        case 0:
            removeOne(str);
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
            
        default: ;
        }
    }
}
