/*
 * RomanToInteger.cpp
 *
 *  Created on: Sep 26, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*
 * Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Converting Roman Numerals to Decimal lying between 1 to 3999
Given a Romal numeral, find its corresponding decimal value.

Example:

Input : IX
Output : 9

Input : XL
Output : 40

Input : MCMIV
Output :  1904
M is a thousand, CM is nine hundred
and IV is four

Roman numerals are based on below symbols.
===========================================

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

A number in Roman Numerals is a string of these symbols written in descending order(e.g. M’s first, followed by D’s, etc.).
However, in a few specific cases, to avoid four characters being repeated in succession (such as IIII or XXXX),
subtractive notation is often used as follows:

I placed before V or X indicates one less, so four is IV (one less than 5) and 9 is IX (one less than 10).
X placed before L or C indicates ten less, so forty is XL (10 less than 50) and 90 is XC (ten less than a hundred).
C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred)
and nine hundred is CM (a hundred less than a thousand).
Algorithm to convert Roman Numerals to Integer Number :

1: Split the Roman Numeral string into Roman Symbols (character).
2: Convert each symbol of Roman Numerals into the value it represents.
3: Take symbol one by one from starting from index 0:
	3A: If current value of symbol is greater than or equal to the value of next symbol, then add this value to the running total.
	3B: else subtract this value by adding the value of next symbol to the running total.
 */

// This function returns value of a Roman symbol
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

// Returns decimal value of roman numaral
int romanToDecimal(string &str)
{
    // Initialize result
    int res = 0;

    // Traverse given input
    for (int i=0; i<str.length(); i++)
    {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);

        if (i+1 < str.length())
        {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i+1]);

            // Comparing both values
            if (s1 >= s2)
            {
                // Value of current symbol is greater
                // or equal to the next symbol
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++; // Value of current symbol is
                     // less than the next symbol
            }
        }
        else
        {
        	// there is no next symbol
            res = res + s1;
            i++;
        }
    }
    return res;
}

// Driver Program
int main()
{
    // Considering inputs given are valid
    string str ="MCMIV";
    cout << "Integer form of Roman Numeral is "
         << romanToDecimal(str) << endl;

    return 0;
}
