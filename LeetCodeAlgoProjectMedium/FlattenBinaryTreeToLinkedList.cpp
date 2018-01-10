/*
 * FlattenBinaryTreeToLinkedList.cpp
 *
 *  Created on: Dec 21, 2017
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
 * Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

 *
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {

	}
};

class Solution {
	private:
	TreeNode *prev = NULL;

public:
    void flatten(TreeNode* root)
    {
    	if (root == NULL)
    	        return;
    	    flatten(root->right);
    	    flatten(root->left);
    	    root->right = prev;
    	    root->left = NULL;
    	    prev = root;
    }

    void flatten2(TreeNode *root)
    {
    	while (root)
    	{
    		if (root->left && root->right)
    		{
    			TreeNode* t = root->left;
    			while (t->right)
    				t = t->right;
    			t->right = root->right;
    		}

            if(root->left)
    		    root->right = root->left;
    		root->left = NULL;
    		root = root->right;
    	}
    }

};


int main(){


	return 0;

}
