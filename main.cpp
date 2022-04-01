#include <iostream>

#include "funcs.h"

void print(std::vector<double> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main()
{
  std::vector<double> e = frequency("Excellent work, Mr. David.");
  print(e);
  std::cout << "\n";
  std::string x  = encryptCaesar("Hello World my name is Ian", 26);
  std::cout << "\n";
  std::string v = solve(encryptCaesar("Hello World and Cpp", 26));
  std::cout << x << std::endl;
  std::cout << v << std::endl;
  return 0;
}