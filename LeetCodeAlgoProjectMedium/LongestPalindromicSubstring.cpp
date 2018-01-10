/*
 * LongestPalindromicSubstring.cpp
 *
 *  Created on: Dec 28, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

/*
 *
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"
Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"
Output: "bb"

 */

/*
 * Method 2 ( Dynamic Programming )
The time complexity can be reduced by storing results of subproblems. The idea is similar to this post.
We maintain a boolean table[n][n] that is filled in bottom up manner. The value of table[i][j] is true,
if the substring is palindrome, otherwise false. To calculate table[i][j], we first check the value of table[i+1][j-1],
if the value is true and str[i] is same as str[j], then we make table[i][j] true. Otherwise, the value of table[i][j] is made false.
 */

class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.length(); // get length of input string

        // table[i][j] will be false if substring str[i..j]
        // is not palindrome.
        // Else table[i][j] will be true
        bool table[n][n];
        memset(table, 0, sizeof(table));

        // All substrings of length 1 are palindromes
        int maxLength = 1;
        for (int i = 0; i < n; ++i)
            table[i][i] = true;

        // check for sub-string of length 2.
        int start = 0;
        for (int i = 0; i < n-1; ++i)
        {
            if (str[i] == str[i+1])
            {
                table[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for lengths greater than 2. k is length
        // of substring
        for (int k = 3; k <= n; ++k)
        {
            // Fix the starting index
            for (int i = 0; i < n-k+1 ; ++i)
            {
                // Get the ending index of substring from
                // starting index i and length k
                int j = i + k - 1;

                // checking for sub-string from ith index to
                // jth index iff str[i+1] to str[j-1] is a
                // palindrome
                if (table[i+1][j-1] && str[i] == str[j])
                {
                    table[i][j] = true;

                    if (k > maxLength)
                    {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }

        return str.substr(start,start+maxLength-1);
    }
};

int main(){


	return 0;

}
