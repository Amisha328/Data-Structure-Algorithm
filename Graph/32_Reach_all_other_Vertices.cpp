//  Minimum Number of Vertices to Reach All Nodes
// Problem link:
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// https://www.codingninjas.com/codestudio/problem-details/minimum-number-of-vertices-to-reach-all-nodes_1377922

/*
Intution: node with indegree 0 can't be visited through any other path so, it need to be included.
Example:
[[1,2],[1,0],[0,2]]
Indegree:
2 -> 2
0 -> 1
1 -> 0
so, [1] is the only node through with all other nodes can be traversed
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> nodeSet;
        vector<int> indegree(n);
        for(auto &it: edges){
            indegree[it[1]]++;
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) 
                nodeSet.push_back(i);
        }
        return nodeSet;
    }
};