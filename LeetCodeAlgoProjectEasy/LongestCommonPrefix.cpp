/*
 * LongestCommonPrefix.cpp
 *
 *  Created on: Sep 28, 2017
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
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 */

class Solution {
public:

	static int findMinLen(vector<string> & strs){
		int min = strs[0].length();

		for(int i=1;i<strs.size();i++){
			if(strs[i].length() < min){
				min = strs[i].length();
			}
		}
		return min;
	}
	/*
	 * Time Complexity : Since we are iterating through all the characters of all the strings,
	 * so we can say that the time complexity is O(N M) where,
	 * N = Number of strings
	 * M = Length of the largest string string
	 */
    static string longestCommonPrefix(vector<string>& strs) {

    	int minLen = findMinLen(strs);

    	string result; // our resultant string
    	char current; // the current character

    	for(int i=0;i<minLen;i++){


    		// Current character (must be same in all strings to be part of result)
    		current = strs[0][i];
    		for(int j=1;j<strs.size();j++){
    			if(strs[j][i] != current){
    				return result;
    			}
    		}
    		// Append to result
    		result.push_back(current);
    	}
    	return result;
    }
};

int main(){

	// the iterator constructor can also be used to construct from arrays:
	string mystrings[4] = {"geeksforgeeks", "geeks","geek", "geezer"};
	std::vector<string> strs;
	for(int i=0;i<4;i++){
		strs.push_back(mystrings[i]);
	}
	string result = Solution::longestCommonPrefix(strs);
	cout<<result<<endl;

	return 0;

}
