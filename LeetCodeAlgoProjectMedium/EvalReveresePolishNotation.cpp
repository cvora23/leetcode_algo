/*
 * EvalReveresePolishNotation.cpp
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

class Solution {
	public:

	int evalRPN(vector<string>& tokens) {
        int a,b;
		stack<int> S;
		for (string s : tokens) {
			if(s.compare("+")) {
				b = S.top();
				S.pop();
				a = S.top();
				S.pop();
				S.push(a+b);
			}
			else if(s.compare("/")) {
				b = S.top();
				S.pop();
				a = S.top();
				S.pop();
				S.push(a / b);
			}
			else if(s.compare("*")) {
				b = S.top();
				S.pop();
				a = S.top();
				S.pop();
				S.push(a * b);
			}
			else if(s.compare("-")) {
				b = S.top();
				S.pop();
				a = S.top();
				S.pop();
				S.push(a - b);
			}
			else {
				S.push(atoi(s.c_str()));
			}
		}
		return S.top();
	}
};


int main(){


	return 0;

}
