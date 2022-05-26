// Critical Connections
// Problem link: https://leetcode.com/problems/critical-connections-in-a-network/
// https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnection;
    void dfs(int node, int parent, vector<int> &visited, vector<vector<int>>& connections, vector<int> &timeOfInsertion,
            vector<int> &lowestTimeOfInsertion, int &timer){
        visited[node] = 1;
        timeOfInsertion[node] = lowestTimeOfInsertion[node] = timer++;
        for(auto it: connections[node]){
            if(it == parent) continue; 
            if(!visited[it]){
                dfs(it, node, visited, connections, timeOfInsertion, lowestTimeOfInsertion, timer);
                lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[it], lowestTimeOfInsertion[node]);
                if(lowestTimeOfInsertion[it] > timeOfInsertion[node])
                    criticalConnection.push_back({node, it});
            }
            // if adjacent node is already visited update the lowestTimeOfInsertion of node with the adjacent's timeOfInsertion value
            else
              lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], timeOfInsertion[it]);  
        }
    }
        
        
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < connections.size() ; i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> timeOfInsertion(n, -1);
        vector<int> lowestTimeOfInsertion(n, -1);
        vector<int> visited(n, 0);
        // Performing simple DFS algorithm
        int timer = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                dfs(i, -1, visited, adj, timeOfInsertion, lowestTimeOfInsertion, timer);
        }
        return criticalConnection;
    }
};