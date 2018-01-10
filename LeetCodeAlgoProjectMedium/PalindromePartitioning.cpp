/*
 * PalindromePartitioning.cpp
 *
 *  Created on: Dec 24, 2017
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
 * Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
 */

/*
 * The Idea is simple: loop through the string, check if substr(0, i) is palindrome.
 * If it is, recursively call dfs() on the rest of sub string: substr(i+1, length).
 * keep the current palindrome partition so far in the 'path' argument of dfs().
 * When reaching the end of string, add current partition in the result.
 */
class Solution {

public:
    vector< vector<string> > partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;

        vector<string> path;
        dfs(0, s, path, ret);

        return ret;
    }

    void dfs(int index, string& s, vector<string>& path, vector< vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

int main(){

	{
		Solution solution;
		vector< vector<string> > result = solution.partition("aab");
		for(int i=0;i<result.size();i++){
			cout<<"[";
			for(int j=0;j<result[i].size();j++){
				cout<<result[i][j]<<",";
			}
			cout<<"]";
			cout<<endl;

		}
	}
	return 0;

}
