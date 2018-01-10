/*
 * CountPrimes.cpp
 *
 *  Created on: Dec 5, 2017
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
School Method
A simple solution is to iterate through all numbers from 2 to n-1 and for every number check if it divides n.
If we find any number that divides, we return false.

Below is C++ implementation of this method.
*/

// A school method based C++ program to check if a
// number is prime
// Time complexity of this solution is O(n)


using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)  return false;

    // Check from 2 to n-1
    for (int i=2; i<n; i++)
        if (n%i == 0)
            return false;

    return true;
}

/*
 * Optimized School Method
We can do following optimizations:

Instead of checking till n, we can check till √n because a larger factor of n must be a multiple of smaller
factor that has been already checked.
 */

// A optimized school method based C++ program to check
// if a number is prime
// Time complexity of this solution is O(√n)

bool isPrime2(int n)
{
    // Corner case
    if (n <= 1)  return false;

    for (int i=2; i*i<=n; i=i++)
        if (n%i == 0)
           return false;

    return true;
}

/*
 * Count the number of prime numbers less than a non-negative number, n.
 */

int countNumOfPrimes(int n){
	int count = 0;
	for(int i=0;i<n;i++){
		if(isPrime2(i)){
			count++;
		}
	}
	return count;
}

int main(){


	return 0;

}
