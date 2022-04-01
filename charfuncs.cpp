#include <iostream>
#include <cmath>
#include <limits>
#include "charfuncs.h"
#include <cctype>



int countChar(std::string str, char c)
{
  int count = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == c)
    {
      count++;
    }
  }
  return count;
}

int countAlpha(std::string str)
{
  int count = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (isAlpha(str[i]))
    {
      count++;
    }
  }
  return count;
}

char lower(char c)
{
  char result = c;
  if (c >= 65 && c <= 90)
  {
    result = c + 32;
  }
  return result;
}