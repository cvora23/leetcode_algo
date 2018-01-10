/*
 * RangeSumQuery.cpp
 *
 *  Created on: Dec 8, 2017
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
 * The idea is fairly straightforward: create an array accu that stores the accumulated sum for nums
 * such that accu[i] = nums[0] + ... + nums[i - 1] in the initializer of NumArray.
 * Then just return accu[j + 1] - accu[i] in sumRange.
 * You may try the example in the problem statement to convince yourself of this idea.
 */

class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};


int main(){


	return 0;

}
