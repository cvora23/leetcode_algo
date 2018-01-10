/*
 * PlusOne.cpp
 *
 *  Created on: Dec 4, 2017
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
 * Given a non-negative integer represented as a non-empty array of digits, add plus one to the integer.
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 * The digits are stored such that the most significant digit is at the head of the list.
 */

class Solution {
public:
    static vector<int> plusOne(vector<int>& digits) {

    	int n = digits.size();
    	for(int i=n-1;i>=0;i--){

    		if(digits[i] < 9){
    			digits[i]++;
    			return digits;
    		}

    		digits[i] = 0;

    	}

    	vector <int>result(digits.size()+1);
    	result[0] = 1;
    	for(int i=0;i<n;i++){
    		result[i+1] = digits[i];
    	}

    	return result;

    }
};

void printResult(vector<int>& result){

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;

}

int main(){

	{
		int dataArray[] = {1,2,3,4};
		unsigned int dataArraySize = sizeof(dataArray)/sizeof(dataArray[0]);
		vector<int> dataVec;

		copy(&dataArray[0],&dataArray[dataArraySize],back_inserter(dataVec));

		vector<int> result = Solution::plusOne(dataVec);
		printResult(result);
	}

	{
		int dataArray[] = {1,2,9,4};
		unsigned int dataArraySize = sizeof(dataArray)/sizeof(dataArray[0]);
		vector<int> dataVec;

		copy(&dataArray[0],&dataArray[dataArraySize],back_inserter(dataVec));

		vector<int> result = Solution::plusOne(dataVec);
		printResult(result);
	}

	{
		int dataArray[] = {9,9,9,9};
		unsigned int dataArraySize = sizeof(dataArray)/sizeof(dataArray[0]);
		vector<int> dataVec;

		copy(&dataArray[0],&dataArray[dataArraySize],back_inserter(dataVec));

		vector<int> result = Solution::plusOne(dataVec);
		printResult(result);
	}


	return 0;

}
