#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "decrypt.h"


int main()
{
  std::cout << solve(encryptCaesar("Hello World! My name is Ian.", 22)) << "\n\n";
  
  return 0;
}