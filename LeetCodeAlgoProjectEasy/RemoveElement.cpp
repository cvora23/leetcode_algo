/*
 * RemoveElement.cpp
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
 * Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

 *
 */

class Solution {
public:
	/*
	 * Approach #1 (Two Pointers) [Accepted]
	 * Intuition
	 * Since question asked us to remove all elements of the given value in-place, we have to handle it with O(1) O(1) extra space.
	 * How to solve it? We can keep two pointers ii and jj, where ii is the slow-runner while jj is the fast-runner.
	 * Algorithm
	 * When nums[j]nums[j] equals to the given value, skip this element by incrementing jj.
	 * As long as nums[j] \neq valnums[j]≠val, we copy nums[j]nums[j] to nums[i]nums[i] and increment both indexes at the same time.
	 * Repeat the process until jj reaches the end of the array and the new length is ii.
	 * This solution is very similar to the solution to Remove Duplicates from Sorted Array.
	 */
    static int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
    /*
     * Approach #2 (Two Pointers - when elements to remove are rare) [Accepted]
     * Intuition
     * Now consider cases where the array contains few elements to remove.
     * For example, nums = [1,2,3,5,4], val = 4 nums=[1,2,3,5,4],val=4.
     * The previous algorithm will do unnecessary copy operation of the first four elements.
     * Another example is nums = [4,1,2,3,5], val = 4nums=[4,1,2,3,5],val=4.
     * It seems unnecessary to move elements [1,2,3,5][1,2,3,5] one step left as the problem description mentions
     * that the order of elements could be changed.
     * Algorithm
     * When we encounter nums[i] = val nums[i]=val, we can swap the current element out with the last element
     * and dispose the last one. This essentially reduces the array's size by 1.
     * Note that the last element that was swapped in could be the value you want to remove itself.
     * But don't worry, in the next iteration we will still check this element.
     */
    int removeElement2(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;

    }
};

int main(){

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {3,2,2,3};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

		cout<<"Size is "<<Solution::removeElement(nums,3)<<endl;

		for(int i=0;i<nums.size();i++){
			cout<<nums[i]<<endl;
		}
	}

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,1,1,2,2,3};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

		cout<<"Size is "<<Solution::removeElement(nums,3)<<endl;

		for(int i=0;i<nums.size();i++){
			cout<<nums[i]<<endl;
		}
	}

	{

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {1,2,3,4,4,5,6};
		std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

		cout<<"Size is "<<Solution::removeElement(nums,3)<<endl;

		for(int i=0;i<nums.size();i++){
			cout<<nums[i]<<endl;
		}
	}

	return 0;

}
