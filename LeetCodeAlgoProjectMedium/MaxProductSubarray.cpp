/*
 * MaxProductSubarray.cpp
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
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 */

class Solution {
 // author : s2003zy
 // weibo : http://weibo.com/574433433
 // blog : http://s2003zy.com
 // Time : O(n)
 // Space : O(1)
 public:
    static int maxProduct(int A[], int n) {
    	int frontProduct = 1;
    	int backProduct = 1;
  		int ans = INT_MIN;
  		for (int i = 0; i < n; ++i) {
  			frontProduct *= A[i];
  			backProduct *= A[n - i - 1];
  			ans = max(ans,max(frontProduct,backProduct));
  		    frontProduct = frontProduct == 0 ? 1 : frontProduct;
  		    backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};

int main(){
	{
		int array[6] = {2,3,-2,4,8,2};
		cout<<Solution::maxProduct(array,6)<<endl;
	}
	{
		int array[6] = {2,3,-2,-4,8,2};
		cout<<Solution::maxProduct(array,6)<<endl;
	}
	return 0;

}
