/*
 * LargestNumber.cpp
 *
 *  Created on: Dec 30, 2017
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
 * Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
 */

/*
 *
For example:

String s1 = "9";
String s2 = "31";

String case1 =  s1 + s2; // 931
String case2 = s2 + s1; // 319

Apparently, case1 is greater than case2 in terms of value.
So, we should always put s1 in front of s2.
 */

bool myfunction(string &s1, string &s2)
{
	return s1+s2>s2+s1;
}


class Solution {
public:
    static string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), myfunction);
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};

int main(){

	{
		vector<int> num;
		num.push_back(9);
		num.push_back(31);
		cout<<Solution::largestNumber(num)<<endl;
	}

	{
		vector<int> num;
		num.push_back(3);
		num.push_back(30);
		num.push_back(34);
		num.push_back(5);
		num.push_back(9);
		cout<<Solution::largestNumber(num)<<endl;

	}

	return 0;

}
