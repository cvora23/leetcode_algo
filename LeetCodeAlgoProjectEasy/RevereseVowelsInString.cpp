/*
 * RevereseVowelsInString.cpp
 *
 *  Created on: Dec 8, 2017
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

class Solution {
public:
    static string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

int main(){

	cout<<Solution::reverseVowels("hello")<<endl;
	cout<<Solution::reverseVowels("leetcode")<<endl;
	return 0;

}
