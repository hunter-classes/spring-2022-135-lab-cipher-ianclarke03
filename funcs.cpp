#include <iostream>
#include "funcs.h"
#include <vector>
#include <math.h>
#include <stdio.h>
#include <fstream>

// add functions here


int charIndex(char o)
{
    int ascii = (int) o;
    if((isupper(o))){
       ascii -= (int) 'A';
    }
    else{
        ascii -= (int)'a';
    }
    return ascii % 26;
}


char shiftChar(char o, int sh)
{
    int index;
    if(sh == 0 || !isalpha(o)){
        return o;
    }
    if (sh > 0){
        int a;

        if(isupper(o)){
            a = (int) 'A';
        }
        else {
            a = (int) 'a';
        }
        index = (((int) o + sh - a) % 26) + a;
    }
    else{
        int z = isupper(o) ? (int) 'Z' : (int) 'z';
        index = (((int) o + sh - z) % 26) + z;
    }
    return (char) index;
}


std::string encryptCaesar(std::string text, int shift)
{
	std::string s = "";
	int i = -1;
	while (text[++i])
		s += shiftChar(text[i], shift);
	return s;
}

std::string decryptCaesar(std::string text, int shift)
{
        std::string r = "";
        int i = -1;
        while (text[++i])
                r += shiftChar(text[i], -shift);
        return r;
}



std::vector<double> frequency(std::string input)
{
	std::vector<double> ints;
	int letters = 0;
    // creates our empty vector with 0.0 values
	while (ints.size() < 26)
		ints.push_back(0.0);

    // loop to check for a letter => increase letters counter + 1 every time
	for (int i = 0; i < input.length(); i++){

		if (isalpha(input[i])){
			ints.at(charIndex(input[i]))++;
			letters++;
		}
	}
    // sets up my letterFreqs vector for input
	for (int j = 0; j < ints.size(); j++)
		ints.at(j) /= letters;
	return ints;
}
  


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