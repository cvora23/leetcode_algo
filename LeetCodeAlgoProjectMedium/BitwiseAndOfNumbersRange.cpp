/*
 * BitwiseAndOfNumbersRange.cpp
 *
 *  Created on: Dec 27, 2017
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
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	while(n > m){
    		n &= (n-1);
    	}
    	return n;
    }
    /*
     * 	The hardest part of this problem is to find the regular pattern.
		For example, for number 26 to 30
		Their binary form are:
		11010
		11011
		11100
		11101
		11110

		Because we are trying to find bitwise AND, so if any bit there are at least one 0 and one 1, it always 0. In this case, it is 11000.
		So we are go to cut all these bit that they are different. In this case we cut the right 3 bit.

		I think after understand this, the code is trivial:
	*/
    int rangeBitwiseAnd2(int m, int n) {
        int i = 0; // i means we have how many bits are 0 on the right
        while(m != n){
          m >>= 1;
          n >>= 1;
          i++;
        }
        return m << i;
    }
};

int main(){


	return 0;

}
