/*
 * ExcelColumn.cpp
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
#define MAX 50

/*
 * Find Excel column name from a given column number
2.8
MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc.
In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.

Given a column number, find its corresponding Excel column name. Following are more examples.

Input          Output
 26             Z
 51             AY
 52             AZ
 80             CB
 676            YZ
 702            ZZ
 705            AAC
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
Thanks to Mrigank Dembla for suggesting the below solution in a comment.

Suppose we have a number n, let’s say 28. so corresponding to it we need to print the column name.
We need to take remainder with 26.

If remainder with 26 comes out to be 0 (meaning 26, 52 and so on) then we put ‘Z’ in the output string and
new n becomes n/26 -1 because here we are considering 26 to be ‘Z’ while in actual it’s 25th with respect to ‘A’.

Similarly if the remainder comes out to be non zero. (like 1, 2, 3 and so on) then we need to just insert the
char accordingly in the string and do n = n/26.

Finally we reverse the string and print.

Example:
n = 700

Remainder (n%26) is 24. So we put ‘X’ in output string and n becomes n/26 which is 26.

Remainder (26%26) is 0. So we put ‘Z’ in output string and n becomes n/26 -1 which is 0.

Following is C++ implementation of above approach.
 */

void printExcelColNameFromColNum(int n){
    char str[MAX];  // To store result (Excel column name)
    int i = 0;  // To store current index in str which is result

    while (n>0)
    {
        // Find remainder
        int rem = n%26;

        // If remainder is 0, then a 'Z' must be there in output
        if (rem==0)
        {
            str[i++] = 'Z';
            n = (n/26)-1;
        }
        else // If remainder is non-zero
        {
            str[i++] = (rem-1) + 'A';
            n = n/26;
        }
    }
    str[i] = '\0';

    // Reverse the string and print result
    reverse(str, str + strlen(str));
    cout << str << endl;

    return;
}

void printExcelColNumFromColName(string s){

	int result = 0;
	for(const auto& c : s){
		result *= 26;
		result += c - 'A' + 1;
	}
	cout<<result<<endl;
}

int main(){

	printExcelColNameFromColNum(26);
	printExcelColNameFromColNum(51);
	printExcelColNameFromColNum(52);
	printExcelColNameFromColNum(80);
	printExcelColNameFromColNum(676);
	printExcelColNameFromColNum(702);
	printExcelColNameFromColNum(705);

    printExcelColNumFromColName("CDA");


	return 0;

}
