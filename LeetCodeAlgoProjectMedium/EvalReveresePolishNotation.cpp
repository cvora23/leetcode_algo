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

/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

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
