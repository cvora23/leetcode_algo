/*
 * CourseSchedule.cpp
 *
 *  Created on: Dec 27, 2017
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
#include <unordered_set>

using namespace std;

/*
 * There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0,
and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
 */

/*
 * As suggested by the hints, this problem is equivalent to detecting a cycle in the graph represented by prerequisites.
 * Both BFS and DFS can be used to solve it using the idea of topological sort. If you find yourself unfamiliar with these concepts,
 * you may refer to their wikipedia pages. Specifically, you may only need to refer to the link in the third hint to solve this problem.
 * Since pair<int, int> is inconvenient for the implementation of graph algorithms, we first transform it to a graph.
 * If course u is a prerequisite of course v, we will add a directed edge from node u to node v.
 */

class Solution {

private:
	vector< unordered_set<int> > make_graph(int numCourses, vector< pair<int, int> >& prerequisites)
	{
		vector< unordered_set<int> > graph(numCourses);
		for (auto pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}

    vector<int> compute_indegree(vector< unordered_set<int> >& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }

public:
    bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites) {
        vector< unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for (; j < numCourses; j++)
            {
                if (!degrees[j]) break;
            }
            if (j == numCourses)
            {
            	return false;
            }
            degrees[j] = -1;
            for (int neigh : graph[j])
            {
                degrees[neigh]--;
            }
        }
        return true;
    }
};

int main(){


	return 0;

}
