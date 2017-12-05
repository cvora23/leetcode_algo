/*
 * SearchInserchPosition.cpp
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
#include <stack>

using namespace std;

/*
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
 */

class Solution {
public:

	static int searchInsert(vector<int>& nums,int start,int end,int target){

		int mid  = (start + end)/2;

		if(end < start){
			if(target < nums[0]){
				return 0;
			}else if(target > nums[nums.size()-1]){
				return nums.size();
			}
		}

		if(nums[mid] == target){
			return mid;
		}else if((target>nums[mid]) && (target<nums[mid+1])){
			return mid+1;
		}else if(target < nums[mid]){
			return searchInsert(nums,start,mid-1,target);
		}else if(target > nums[mid]){
			return searchInsert(nums,mid+1,end,target);
		}
	}

    static int searchInsert(vector<int>& nums, int target) {
    	return searchInsert(nums,0,nums.size()-1,target);
    }
};

int main(){

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,3,5,6};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );
		cout<<"Index is "<<Solution::searchInsert(nums,5)<<endl;

	}

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,3,5,6};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );
		cout<<"Index is "<<Solution::searchInsert(nums,2)<<endl;

	}

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,3,5,6};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );
		cout<<"Index is "<<Solution::searchInsert(nums,7)<<endl;

	}

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,3,5,6};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );
		cout<<"Index is "<<Solution::searchInsert(nums,0)<<endl;

	}

	return 0;

}
