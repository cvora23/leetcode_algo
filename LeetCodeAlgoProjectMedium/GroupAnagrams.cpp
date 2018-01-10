/*
 * GroupAnagrams.cpp
 *
 *  Created on: Dec 31, 2017
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
 * Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
 *
 */

/*
 * With using sort
 */
class Solution {
	public:
	vector< vector<string> > groupAnagrams(vector<string> strs) {
		vector< vector<string> > res;
        map< string, vector<string> > anagramMap;
        map< string, vector<string> >::iterator anagramMapItr;

        for (int i=0;i<strs.size();i++) {
        	string temp = strs[i];
            std::sort(temp.begin(), temp.end());
            anagramMap[temp].push_back(strs[i]);
        }
        int index = -1;
        for(anagramMapItr=anagramMap.begin();anagramMapItr!=anagramMap.end();anagramMapItr++){
        	index++;
        	for(int i=0;i<anagramMapItr->second.size();i++){
        		res[index].push_back(anagramMapItr->second[i]);
        	}
        }
        return res;
    }
};

/*
 * Without using sort
 */
class Solution1{

private:
	 int prime[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
public:
		vector< vector<string> > groupAnagrams(vector<string> strs) {
			vector< vector<string> > res;
	        map< int, vector<string> > anagramMap;
	        map< int, vector<string> >::iterator anagramMapItr;

	        for (int i=0;i<strs.size();i++) {
	        	int key = 1;
	        	for(int j=0;j<strs[i].length();j++){
	        		key *= prime[strs[i][j]- 'a'];
	        	}
	            anagramMap[key].push_back(strs[i]);
	        }
	        int index = -1;
	        for(anagramMapItr=anagramMap.begin();anagramMapItr!=anagramMap.end();anagramMapItr++){
	        	index++;
	        	for(int i=0;i<anagramMapItr->second.size();i++){
	        		res[index].push_back(anagramMapItr->second[i]);
	        	}
	        }
	        return res;
		}
};

int main(){


	return 0;

}
