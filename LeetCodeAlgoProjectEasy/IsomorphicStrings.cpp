/*
 * IsomorphicStrings.cpp
 *
 *  Created on: Dec 5, 2017
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
 * Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {

    	if(s.length() != t.length()){
    		return false;
    	}
    	std::map<char,char> firstMap;
    	std::map<char,char>::iterator firstItr;

    	std::map<char,char> secondMap;
    	std::map<char,char>::iterator secondItr;

    	for(int i=0;i<s.length();i++){

    		firstItr = firstMap.find(s[i]);
    		secondItr = secondMap.find(t[i]);

        	if((firstItr != firstMap.end()) && (secondItr != secondMap.end())){
        		if(firstItr->second != secondItr->first && firstItr->first != secondItr->second){
        			return false;
        		}
        	}else{

        		firstMap[s[i]] = t[i];
        		secondMap[t[i]] = s[i];
        	}
    	}

    	return true;




    }

    bool isIsomorphic2(string s, string t) {
          int m1[256] = {0}, m2[256] = {0}, n = s.size();
          for (int i = 0; i < n; ++i) {
              if (m1[s[i]] != m2[t[i]]) return false;
              m1[s[i]] = i + 1;
              m2[t[i]] = i + 1;
          }
          return true;
      }
};


int main(){


	return 0;

}
