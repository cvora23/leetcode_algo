/*
 * ArrayWithDuplicates.cpp
 *
 *  Created on: Dec 6, 2017
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
#include <unordered_set>

using namespace std;

/*
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j
 * in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;

       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;

       for (int i = 0; i < nums.size(); i++)
       {
    	   // erase element if already passed k positions
           if (i > k)
        	   s.erase(nums[i - k - 1]);
           // if element present within k positions, return true
           if (s.find(nums[i]) != s.end())
        	   return true;
           // else insert into ordered_set if not seen yet
           s.insert(nums[i]);
       }

       return false;
    }
};

int main(){


	return 0;

}
