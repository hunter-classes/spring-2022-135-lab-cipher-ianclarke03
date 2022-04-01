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

