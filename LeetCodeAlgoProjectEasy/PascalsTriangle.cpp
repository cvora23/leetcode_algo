/*
 * PascalsTriangle.cpp
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
 * Pascal’s Triangle
2.9
Pascal’s triangle is a triangular array of the binomial coefficients.
Write a function that takes an integer value n as input and prints first n lines of the Pascal’s triangle.
Following are the first 6 rows of Pascal’s Triangle.

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1


We strongly recommend that you click here and practice it, before moving on to the solution.


Method 1 ( O(n^3) time complexity )
Number of entries in every line is equal to line number. For example, the first line has “1”,
the second line has “1 1”, the third line has “1 2 1”,.. and so on. Every entry in a line is value of a Binomial Coefficient.
The value of ith entry in line number line is C(line, i). The value can be calculated using following formula.

C(line, i)   = line! / ( (line-i)! * i! )
A simple method is to run two loops and calculate the value of Binomial Coefficient in inner loop.



 */


// A simple O(n^3) program for Pascal's Triangle
#include <stdio.h>

// See http://www.geeksforgeeks.org/archives/25621 for details of this function
int binomialCoeff(int n, int k);

// Function to print first n lines of Pascal's Triangle
void printPascal(int n)
{
  // Iterate through every line and print entries in it
  for (int line = 0; line < n; line++)
  {
    // Every line has number of integers equal to line number
    for (int i = 0; i <= line; i++)
      printf("%d ", binomialCoeff(line, i));
    printf("\n");
  }
}

/*
 * Space and time efficient Binomial Coefficient
2.6
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).
For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.

We have discussed a O(n*k) time and O(k) extra space algorithm in this post. The value of C(n, k) can be
calculated in O(k) time and O(1) extra space.

C(n, k) = n! / (n-k)! * k!
        = [n * (n-1) *....* 1]  / [ ( (n-k) * (n-k-1) * .... * 1) *
                                    ( k * (k-1) * .... * 1 ) ]
After simplifying, we get
C(n, k) = [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]

Also, C(n, k) = C(n, n-k)  // we can change r to n-r if r > n-r
Following implementation uses above formula to calculate C(n, k)
 */

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// Driver program to test above function
int main()
{
  int n = 7;
  printPascal(n);
  return 0;
}
