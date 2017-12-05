/*
 * RemoveDupsSortedArr.cpp
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
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,Given input array nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

class Solution {
public:
	/*
	 * Approach #1 (Two Pointers) [Accepted]
	 * Algorithm
	 * Since the array is already sorted, we can keep two pointers ii and jj,
	 * where ii is the slow-runner while jj is the fast-runner.
	 * As long as nums[i] = nums[j]nums[i]=nums[j], we increment jj to skip the duplicate.
	 * When we encounter nums[j] \neq nums[i]nums[j]≠nums[i], the duplicate run has ended
	 * so we must copy its value to nums[i + 1] nums[i+1]. ii is then incremented and we repeat the same
	 * process again until jj reaches the end of array.
	 */

    static int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main(){

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,1,2};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

		cout<<"Size is "<<Solution::removeDuplicates(nums)<<endl;

		for(int i=0;i<nums.size();i++){
			cout<<nums[i]<<endl;
		}
	}

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,1,1,2,2,3};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

		cout<<"Size is "<<Solution::removeDuplicates(nums)<<endl;

		for(int i=0;i<nums.size();i++){
			cout<<nums[i]<<endl;
		}
	}

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,2,3,4,4,5,6};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

		cout<<"Size is "<<Solution::removeDuplicates(nums)<<endl;

		for(int i=0;i<nums.size();i++){
			cout<<nums[i]<<endl;
		}
	}

	return 0;

}
