#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cfloat>
#include <cmath>
#include <limits>
#include <cctype>
#include "funcs.h"
#include "caesar.h"
#include "charfuncs.h"
#include "decrypt.h"




std::vector<double> frequency(std::string str){
  std::vector<double> result;
  result.assign(26, 0);
  int letters;
  
  //for (int a = 1; a <= 26; a++)
  //      result.push_back(a);

  for (int i = 0; i < str.length(); i++){

		if (isalpha(str[i])){
			result.at(charIndex(str[i]))++;
			letters++;
      }
    
    }
  
	for (int x = 0; x < result.size(); x++)
		result.at(x) /= letters;

  
	return result;
  }
  


double dist(std::vector<double> v1, std::vector<double> v2)
{
  double result;
  if (v1.size() != v2.size())
  {
    std::cerr << "Error: v1 and v2 sizes not equivalent.\n";
    return 0.0;
  }

  for (int i = 0; i < v1.size(); i++)
  {
    result = pow(v1[i] - v2[i], 2);
  }
  return sqrt(result);
}

/*
std::string solve(std::string encrypted_string)
{
        std::string text = "", s;
        std::ifstream o("sample.txt");
        while (getline(o, s))
                text += s;
        std::vector<double> e = getLetterFreqs(text);
        double min = 100000000, index;
        for (int i = 0; i < 26; i++)
        {
                // creates our empty vector for the encrptyed text
                std::vector<double> check;
                while (check.size() < 26)
                        check.push_back(0.0);
                int letters = 0;
                for (int p = 0; p < encrypted_string.length(); p++){
                        if (isalpha(encrypted_string[p])){
                                int hold = charIndex(encrypted_string[p]) + i;
                                check.at(hold % 26)++;
                                letters++;
                        }
                }
                for (int p = 0; p < check.size(); p++)
                        check.at(p) /= letters;
                double d = distance(check, e);
                if (d < min){
                        index = i;
                        min = d;
                }
        }
        return decryptCaesar(encrypted_string, 26 - index);
}


*/





/*
std::string solve(std::string encryptedString)
{
  int bestRot = 0;
  double closestDist = std::numeric_limits<double>::max(); // max double val
  std::vector<char> alphaChars = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
  };
  // frequencies are in decimal form, NOT percent.
  std::vector<double> alphaLFreqs = {
    .085, .021, .045, .034, .112, .018, .025, .030, .075, .002, .011, .055, .03, .067, .072, .032,
    .002, .076, .057, .07, .036, .01, .013, .003, .018, .003
  };
  std::vector<double> scaledAlphaLFreqs = frequency(alphaLFreqs, (double)countAlpha(encryptedString));

  // for (int k = 0; k < scaledAlphaLFreqs.size(); k++)
  // {
  //   std::cout << std::to_string(alphaChars[k]) << ": " << scaledAlphaLFreqs[k] << "\n";
  // }
  // std::cout << "==========================\n";

  // get alpha character frequencies for each rotation
  for (int i = 0; i < 26; i++)
  {
    std::string currRotStr = encryptCaesar(encryptedString, i);
    std::vector<double> rotAlphaFreqs(26,0);
    for (int j = 0; j < currRotStr.length(); j++)
    {
      char currChar = currRotStr[j];
      if (isalpha(currChar))
      {
        int alphaIndex = lower(currChar) - 96; // 96 makes chars start at 1
        rotAlphaFreqs[alphaIndex] = rotAlphaFreqs[alphaIndex] + 1.0;
      }
    }
    double currDist = dist(frequency, rotAlphaFreqs);
    if (currDist < closestDist)
    {
        closestDist = currDist;
        bestRot = i;
    }
  }
  // std::cout << bestRot << "\n";
  return encryptCaesar(encryptedString, bestRot + 1);
}

*/


double distance(std::vector<double> a, std::vector<double> b)
{
        double d = 0.0;
        for (int i = 0; i < a.size(); i++){
                if (a.at(i) > b.at(i))
                        d += sqrt(pow(a.at(i), 2) - pow(b.at(i), 2));
                else
                        d += sqrt(pow(b.at(i), 2) - pow(a.at(i), 2));
        }
        return d / 26.0;
}

/*

std::string solve(std::string encrypted_string){
  // for each of the 26 rotations of encrypted string:
  std::vector <double> englishFrequencies = {0.082, 0.015, 0.027, 0.047,
			      0.13, 0.022, 0.02, 0.062,
			      0.069, 0.0016, 0.0081, 0.04,
			      0.027, 0.067, 0.078, 0.019,
			      0.0011, 0.059, 0.062, 0.096,
			      0.027, 0.0097, 0.024, 0.0015,
			      0.02, 0.0078};
  
  // make a 26 space vector with the frequencies of all the letters based on encrypted string
  std::vector <double> letterFrequencies;
  letterFrequencies.assign(26, 0);
  int characters = 0;
  int rotate = 0;
  std::string rotated;

  std::string lowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
  std::string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  double min = DBL_MAX;

  for(int i = 0; i < 26; i++){
    // entries will be 0 for those that don't appear in the string
    //letterFrequencies.push_back(0);

    rotated = encryptCaesar(encrypted_string, i);
    
    //if there is that letter in the string -> count how many there are
    for(int j = 0; j < encrypted_string.length(); j++){
      
      //see if the letter of the string is in the alphabet with find
      if(lowerAlphabet.find(rotated[j])!= std::string::npos){
	letterFrequencies[lowerAlphabet.find(rotated[j])] += 1;
	//std::cout << lowerAlphabet.find(rotated[j]) << std::endl;
	characters += 1;
      }else if(upperAlphabet.find(rotated[j]) != std::string::npos){
	letterFrequencies[upperAlphabet.find(rotated[j])] += 1;
	characters += 1;
	}
      }

    int sum = 0;

    for(int j = 0; j < 26; j++){
      if (letterFrequencies[j] > 0){
	letterFrequencies[j] = letterFrequencies[j] / characters;
      }
    }

    //calculate the distance between this vector and the vector of letter frequencies for English
    // rotation with the smallest distance is the solution
    if(min > distance(letterFrequencies, englishFrequencies, 26)){
	min = distance(letterFrequencies, englishFrequencies, 26);
	rotate = i;
      }

    letterFrequencies = {0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0,0, 0, 0,
			      0, 0, 0, 0,
			      0, 0};
    characters = 0;
  }
  std::string decrypted = decryptCaesar(encrypted_string, 26 - rotate);

  return decrypted;
}
*/





std::string solve(std::string encrypted_string)
{
        std::string text = "", s;
        std::ifstream o("sample.txt");
        while (getline(o, s))
                text += s;
        std::vector<double> e = frequency(text);
        double min = 100000000, index;
        for (int i = 0; i < 26; i++)
        {
                // creates our empty vector for the encrptyed text
                std::vector<double> check;
                while (check.size() < 26)
                        check.push_back(0.0);
                int letters = 0;
                for (int p = 0; p < encrypted_string.length(); p++){
                        if (isalpha(encrypted_string[p])){
                                int hold = charIndex(encrypted_string[p]) + i;
                                check.at(hold % 26)++;
                                letters++;
                        }
                }
                for (int p = 0; p < check.size(); p++)
                        check.at(p) /= letters;
                double d = distance(check, e);
                if (d < min){
                        index = i;
                        min = d;
                }
        }
        return decryptCaesar(encrypted_string, 26 - index);
}