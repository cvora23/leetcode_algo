/*
 * TriangleMinSumPath.cpp
 *
 *  Created on: Dec 22, 2017
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

/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

 */

using namespace std;

class Solution {
private:
/*
 * DFS
 */
	void minimumTotalRec(vector< vector<int> >& triangle,int rowIndex,int colIndex,std::set<int> &minSet,int total){

		// Base Condition
		if(rowIndex == triangle.size())
		{
			minSet.insert(total);
			return;
		}
		// Recursive Condition

		// current element
		if(colIndex >= 0 && colIndex < triangle[rowIndex].size())
		{
			total += triangle[rowIndex][colIndex];
		}

		// go below
		if(colIndex >= 0 && colIndex < triangle[rowIndex].size())
		{
			minimumTotalRec(triangle,rowIndex+1,colIndex,minSet,total);
		}
		// go left below
		if(colIndex >= 0 && colIndex < triangle[rowIndex].size())
		{
			minimumTotalRec(triangle,rowIndex+1,colIndex-1,minSet,total);
		}
		// go right below
		if(colIndex >= 0 && colIndex < triangle[rowIndex].size())
		{
			minimumTotalRec(triangle,rowIndex+1,colIndex+1,minSet,total);
		}
	}
public:
	/*
	 * DFS
	 */
    int minimumTotal(vector< vector<int> >& triangle) {
    	std::set<int>minSet;
    	minimumTotalRec(triangle,0,0,minSet,0);
    	std::set<int>::iterator it=minSet.begin();
    	return *it;
    }
    /*
     * DP - bottom up approach
     * ‘Bottom-up’ DP, on the other hand, is very straightforward: we start from the nodes on the bottom row; the min pathsums for
     * these nodes are the values of the nodes themselves.
     * From there, the min pathsum at the ith node on the kth row would be the lesser of the pathsums of its two children plus the
     * value of itself, i.e.:
     * minpath[k][i] = min( minpath[k+1][i], minpath[k+1][i+1]) + triangle[k][i];
     * Or even better, since the row minpath[k+1] would be useless after minpath[k] is computed, we can simply set minpath as a 1D array,
     * and iteratively update itself:
     * For the kth level:
     * minpath[i] = min( minpath[i], minpath[i+1]) + triangle[k][i];
     */
    int minimumTotal2(vector<vector<int> > &triangle)
    {
        vector<int> mini = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        return mini[0];
    }
};

int main(){

	{
		Solution solution;
		vector<int>row1;
		row1.push_back(2);
		vector<int>row2;
		row2.push_back(3);
		row2.push_back(1);
		vector<int>row3;
		row3.push_back(6);
		row3.push_back(5);
		row3.push_back(7);
		vector<int>row4;
		row4.push_back(4);
		row4.push_back(1);
		row4.push_back(8);
		row4.push_back(2);

		vector< vector<int> > triangle;
		triangle.push_back(row1);
		triangle.push_back(row2);
		triangle.push_back(row3);
		triangle.push_back(row4);

		cout<<solution.minimumTotal(triangle)<<endl;
		cout<<solution.minimumTotal2(triangle)<<endl;

	}

	return 0;

}
