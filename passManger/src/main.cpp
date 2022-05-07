#include <iostream>

#include "classes/application/application.h"
#include "classes/enc_dec/enc_dec.h"
#include "classes/misc/misc.h"

int main(int argc, char** argv)
{
  /*
  application app;
  app.run();
  */
  
  std::wstring test(L"IsakIsBadLelV2");

  std::vector<int> pass_key({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});

  encrypter_decrypter::encrypt_string(test, pass_key);
  encrypter_decrypter::decrypt_string(test, pass_key);
  
  std::wcout << test << std::endl;
  
  return 0;
}
