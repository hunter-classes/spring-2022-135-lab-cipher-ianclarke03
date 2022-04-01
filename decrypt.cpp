#include <iostream>
#include <string>
#include "caesar.h"


int charIndex(char o)
{
    int ascii = (int) o;
    if((isupper(o)))
    {
       ascii -= (int) 'A';
    }
    else
    {
        ascii -= (int)'a';
    }
    return ascii % 26;
}
  
std::string decryptCaesar(std::string plaintext, int rshift)
{
    std::string s = "";
    int i = -1;
    while(plaintext[++i])
    {
        s = s + shiftChar(plaintext[i], -rshift);
    }
    return s;

}
