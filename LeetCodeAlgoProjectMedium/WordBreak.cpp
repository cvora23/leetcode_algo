/*
 * WordBreak.cpp
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
#include <queue>
#include <unordered_set>

using namespace std;

/*
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be
 * segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

 */

/*
 * People have posted elegant solutions using DP. The solution I post below using BFS is no better than those.
 * Just to share some new thoughts.

We can use a graph to represent the possible solutions. The vertices of the graph are simply the positions of the
first characters of the words and each edge actually represents a word. For example, the input string is "nightmare",
there are two ways to break it, "night mare" and "nightmare". The graph would be

0-->5-->9

|__ __ _^

The question is simply to check if there is a path from 0 to 9. The most efficient way is traversing the graph using BFS
with the help of a queue and a hash set. The hash set is used to keep track of the visited nodes to avoid repeating the same work.

For this problem, the time complexity is O(n^2) and space complexity is O(n), the same with DP.
This idea can be used to solve the problem word break II. We can simple construct the graph using BFS,
save it into a map and then find all the paths using DFS.
 */

bool wordBreak(string s, unordered_set<string> &dict) {
    // BFS
    queue<int> BFS;
    unordered_set<int> visited;

    BFS.push(0);
    while(BFS.size() > 0)
    {
        int start = BFS.front();
        BFS.pop();
        //cout<<"start = "<<start<<endl;
        if(visited.find(start) == visited.end())
        {
            visited.insert(start);
            for(int j=start; j<s.size(); j++)
            {
                string word(s, start, j-start+1);
                if(dict.find(word) != dict.end())
                {
                	//cout<<"j = "<<j<<endl;
                    BFS.push(j+1);
                    if(j+1 == s.size())
                        return true;
                }
            }
        }
    }

    return false;
}

int main(){

	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("leetcode");
	dict.insert("s");

	string s = "leetcodes";

	cout<<(wordBreak(s,dict)?"true":"false")<<endl;

	return 0;

}
