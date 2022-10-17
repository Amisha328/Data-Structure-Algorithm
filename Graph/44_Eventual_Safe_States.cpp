// Eventual Safe States
// Problem link:
// https://leetcode.com/problems/find-eventual-safe-states/
// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1


#include <bits/stdc++.h>
using namespace std;

// Topological Sort using Kahn's Algorithm
// Implemnetation - BFS

class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
       vector<int> adjRev[V];
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it: graph[i]){
                // Reverse the arrows, as for topological sort we use indegrees
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> safeNodes;
        while(!q.empty())
        {
            int node = q.front();
            safeNodes.push_back(node);
            q.pop();
            for(auto it: adjRev[node]){
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

// Detect Cycle Approach
// Implementation - DFS

class Solution {
    private:
    bool detectCycle(int start, vector<vector<int>>& adj, vector<int> &visited, vector<int> &recStack, vector<int> &checkSafeNode)
    {
            visited[start] = 1; // mark node as visisted
            recStack[start] = 1; // mark node as path visited
            for(auto u: adj[start])
            {
                if(!visited[u] && detectCycle(u, adj, visited, recStack, checkSafeNode))
                {
                    // if cycle exist it can't be safe Node as it can never reach terminal node
                    checkSafeNode[u] = 0; // mark not a safe node
                    return true;
                }
                // if the node has been prevously visisted but it has been visited on the same path, cycle exist
                if(recStack[u]) 
                {
                    // if cycle exist it can't be safe Node as it can never reach terminal node
                    checkSafeNode[u] = 0; // mark not a safe node
                    return true;
                }
                    
            }
            checkSafeNode[start] = 1; // if cycle does not exist it is a safe node.
            recStack[start] = 0; // unmark node as path visited as we have traverse that path.
            return false; // no cycle exist
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> recStack(V, 0);
        vector<int> checkSafeNode(V, 0);
        vector<int> safeNodes;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
               detectCycle(i, adj, visited, recStack, checkSafeNode);
        }
        
        for(int i = 0; i < V; i++)
        {
            if(checkSafeNode[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};