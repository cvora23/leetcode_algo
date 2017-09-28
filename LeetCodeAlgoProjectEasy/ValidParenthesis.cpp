/*
 * ValidParenthesis.cpp
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


class Solution {
public:
    static bool isValid(string expr) {

        stack<char> s;
        char a, b, c;

        // Traversing the Expression
        for (int i=0; i<expr.length(); i++)
        {
            if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
            {
                // Push the element in the stack
                s.push(expr[i]);
            }
            else
            {
                switch (expr[i])
                {
                case ')':

                    // Store the top element in a
                    a = s.top();
                    s.pop();
                    if (a=='{'||a=='[')
                        cout<<"Not Balancedn";
                    break;
                case '}':

                    // Store the top element in b
                    b = s.top();
                    s.pop();
                    if (b=='('||b=='[')
                        cout<<"Not Balancedn";
                    break;
                case ']':

                    // Store the top element in c
                    c=s.top();
                    s.pop();
                    if (c=='('||c=='{')
                        cout<<"Not Balancedn";
                    break;
                }
            }
        }

        // Check Empty Stack
        if (s.empty())
            return true;
        else
            return false;

    }
};

int main(){

	string expr = "{()}[]";
    if(Solution::isValid(expr))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";

	return 0;

}
