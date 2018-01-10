/*
 * Sqrt.cpp
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
 * Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.
 */

int sqrRoot(int num)
{
	if(num==0 || num==1)
		return num;
	int res=1;int i=1;
	while(res< num)
	{
		i++;
		res=i*i;
	}
	if(res==num)
		return i;
	else
		return (i-1);
}

int main(){

	{
	    int x = 11;
	    cout << sqrRoot(x) << endl;
	}


	{
	    int x = 4;
	    cout << sqrRoot(x) << endl;
	}

	return 0;

}
