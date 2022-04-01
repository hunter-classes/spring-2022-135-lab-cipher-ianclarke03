#include <iostream>
#include <cmath>
#include <limits>
#include "caesar.h"
#include <cctype>

char shiftChar(char c, int rShift)
{
  if (!isalpha(c))
  {
    return c;
  }

  int shifted = c + rShift;
  if (shifted > 90 && (c >= 65 && c <= 90))
  {
    int over = shifted - 90 - 1;
    return (char)(65 + over);
  }
  if (shifted > 122 && (c >= 97 && c <= 122)) // lowercase overflow
  {
    // std::cout << "lowercase overflow!\n";
    int over = shifted - 122 - 1;
    return (char)(97 + over);
  }
  return (char)(shifted);
}



std::string encryptCaesar(std::string plaintext, int rshift){
  int len = plaintext.length();
  std::string str = "";
  char let;
  for (int i = 0; i < len; i++){
    let = shiftChar(plaintext[i], rshift);
    str += let;

  }
return str;
}
