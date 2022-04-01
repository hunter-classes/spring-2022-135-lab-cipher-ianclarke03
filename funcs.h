
#pragma once
#include <vector>
#include <iostream>

int charIndex(char o);
char shiftChar(char o, int sh);
std::string encryptCaesar(std::string o, int shift);
std::vector<double> frequency(std::string input);
double distance(std::vector<double> a, std::vector<double> b);
std::string solve(std::string encrypted_string);
