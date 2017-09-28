/*
 * PalindromeNumber.cpp
 *
 *  Created on: Sep 26, 2017
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
 * Determine whether an integer is a palindrome. Do this without extra space.
Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
 */

class Solution {
public:
    static bool isPalindrome(int x) {
    	 // As discussed above, when x < 0, x is not a palindrome.
    	        // Also if the last digit of the number is 0, in order to be a palindrome,
    	        // the first digit of the number also needs to be 0.
    	        // Only 0 satisfy this property.
    	        if(x < 0 || (x % 10 == 0 && x != 0)) {
    	            return false;
    	        }

    	        int revertedNumber = 0;
    	        while(x > revertedNumber) {
    	            revertedNumber = revertedNumber * 10 + x % 10;
    	            x /= 10;
    	        }

    	        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
    	        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
    	        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
    	        return x == revertedNumber || x == revertedNumber/10;
    }
};

int main(){

	cout<<Solution::isPalindrome(121)<<endl;
	cout<<Solution::isPalindrome(321)<<endl;
	cout<<Solution::isPalindrome(-321)<<endl;

	return 0;

}
