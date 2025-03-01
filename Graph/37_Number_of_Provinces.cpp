// Number of Provinces
// Problem link:
// https://leetcode.com/problems/number-of-provinces/
// https://practice.geeksforgeeks.org/problems/number-of-provinces/1
// https://www.codingninjas.com/codestudio/problem-details/find-the-number-of-states_1377943

#include <bits/stdc++.h> 
using namespace std;

class Solution {
private:
    void dfs(vector<int> adj[], int node, vector<int> &visited){
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it])
                dfs(adj, it, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(V, 0);
        int provinces  = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i])
            {
                provinces++;
                dfs(adj, i, visited);
            }       
        }
        return provinces;
    }
};