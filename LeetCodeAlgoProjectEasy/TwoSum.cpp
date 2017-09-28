/*
 * TwoSum.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: chivora
 */

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
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
 * Probably can be done in One-pass
 */

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> resultIndexes;
    	map<int,int>valIndexMap;
    	map<int,int>::iterator valIndexMapItr;
    	map<int,int>::iterator valIndexMapFindItr;

    	for(int i=0;i<nums.size();i++){
    		valIndexMap[nums[i]] = i;
    	}

    	for(valIndexMapItr=valIndexMap.begin();valIndexMapItr != valIndexMap.end();valIndexMapItr++){
    		int value = valIndexMapItr->first;
    		int index = valIndexMapItr->second;

    		int diffValue = target - value;
    		if(diffValue != value){

    			valIndexMapFindItr = valIndexMap.find(diffValue);
    			if(valIndexMapFindItr != valIndexMap.end()){
    				resultIndexes.push_back(index);
    				resultIndexes.push_back(valIndexMapFindItr->second);
    				break;
    			}
    		}
    	}
    	return resultIndexes;
    }
};


int main(){

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {2,7,11,15,7};
	std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

	vector<int>result = Solution::twoSum(nums,9);

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}

	if(result.empty())
		cout<<"Empty"<<endl;

	return 0;

}
