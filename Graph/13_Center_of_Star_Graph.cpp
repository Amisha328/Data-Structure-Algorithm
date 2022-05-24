// Find Center of Star Graph
// Problem link: https://leetcode.com/problems/find-center-of-star-graph/

#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
        int V = edges.size();
        vector<int> adj[V+2];
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 1; i <= V+1; i++)
        {
           if(adj[i].size() == V)
               return i;
        }
        return 0;
    }