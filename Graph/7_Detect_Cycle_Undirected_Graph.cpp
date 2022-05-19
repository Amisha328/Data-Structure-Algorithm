// Detect cycle in an undirected graph
// Problem link:
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#
// https://www.codingninjas.com/codestudio/problem-details/detect-cycle-in-an-undirected-graph_758967

#include <bits/stdc++.h>
using namespace std;

/*
// Using BFS
    bool detectCycle(int s, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> nodeParent;
        nodeParent.push({s, -1});
        visited[s] = 1;
        while(!nodeParent.empty())
        {
            int node = nodeParent.front().first;
            int parent = nodeParent.front().second;
            nodeParent.pop();
            for(auto u : adj[node])
            {
                if(!visited[u])
                {
                    visited[u] = 1;
                    nodeParent.push({u, node});
                }
                else if(u != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
                if (detectCycle(i, adj, visited))
                        return true;
        }
        return false;
    }
*/

// Using DFS
bool detectCycle(int &start, vector<int> adj[], vector<int> &visited, int parent)
{
        visited[start] = 1;
        for(auto u : adj[start])
        {
            if(!visited[u])
            {
                if(detectCycle(u, adj, visited, start))
                    return true;
            }
            else if(u != parent)
                return true;
        }
        return false;
}
bool isCycle(int V, vector<int> adj[]) 
{
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(detectCycle(i, adj, visited, -1))
                    return true;
            }
        }
        return false;
}
int main() 
{
	int V, E;
	cin >> V >> E;
	vector<int> graph[V];
	for(int i = 0; i < E; i++)
	{
		int u, v;
		cin>> u >> v;
		graph[u].push_back(v);
    	          graph[v].push_back(u);
	}
	
	if(isCycle(V, graph))
	  cout<<"True"<<endl;
	else
	  cout<<"False"<<endl;
	return 0;
}