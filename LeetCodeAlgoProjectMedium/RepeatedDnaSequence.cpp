/*
 * RepeatedDnaSequence.cpp
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
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
 * When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 */

class Solution {
private:
	set<string>seen,repeated;
	set<string>::iterator seenItr;
public:
    set<string> findRepeatedDnaSequences(string s) {
    	for(int i=0;i+9 < s.length() ; i++){
            string ten = s.substr(i, 10);
            seenItr = seen.find(ten);
            seen.insert(ten);
            // if seen before put it in repeated
            if(seenItr != seen.end())
            {
            	repeated.insert(ten);
            }
    	}
    	return repeated;
    }
};

int main(){

	{
		Solution solution;
		set<string> result = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
		for(set<string>::iterator it = result.begin();it != result.end();it++){
			cout<<*it<<endl;
		}
	}

	return 0;

}
