/*
 * ReverseInteger.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: chivora
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
 * Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of
1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
 */

class Solution {
public:

	/* If there is no overflow, the function places the resultant = sum a+b in “result” and
	    returns 0, otherwise it returns -1 */
	 static int addOvf(int a,int multiple, int b)
	 {
	     int result = a + b;
	     int result2 = a*multiple;
	     if(a > 0 && result2 < 0){
	    	 return 0;
	     }else{
	    	 a = a*multiple;
	     }

	     if(a > 0 && b > 0 && result < 0)
	         return 0;
	     if(a < 0 && b < 0 && result > 0)
	         return 0;
	     return 1;
	 }

    static int reverse(int x) {
    	int result = 0;
    	int sign = 1;
    	if(x<0){
    		sign = -1;
    		x = sign*x;
    	}
    	while(x>0){
    		int remainder =  x%10;
    		if(addOvf(result,10,remainder) == 0){
    			return 0;
    		}
    		result = result * 10 + remainder;
    		x = x/10;
    	}
    	return result *  sign;
    }
};


int main(){

	cout<<Solution::reverse(123)<<endl;
	cout<<Solution::reverse(-123)<<endl;
	cout<<Solution::reverse(1000000003)<<endl;
	cout<<Solution::reverse(100000000)<<endl;

	return 0;

}
