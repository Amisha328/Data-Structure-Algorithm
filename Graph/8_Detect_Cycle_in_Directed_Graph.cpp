// Detect cycle in a directed graph
// Problem link:
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/#
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626


#include <bits/stdc++.h>
using namespace std;

/*
// DFS Traversal
// recStack is maintained that is initially false
// It get true when node enters the recursion and get false again when recusive call is over.
// If it remains true i.e it does not got out of recusion hence there exist a loop.
bool detectCycle(int start, vector<int> adj[], vector<int> &visited, vector<int> &recStack)
{
        visited[start] = 1;
        recStack[start] = 1;
        for(auto u: adj[start])
        {
            if(!visited[u] && detectCycle(u, adj, visited, recStack))
                return true;
            if(recStack[u])
                return true;
        }
        recStack[start] = 0;
        return false;
}

bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        vector<int> recStack(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i] && detectCycle(i, adj, visited, recStack))
                return true;
        }
        return false;
}
*/

// BFS Traversal - Kahn's algorithm
bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++)
        {
            for(auto x: adj[i])
                indegree[x]++;
        }
        queue<int> q;
        for(int i = 0; i < V; i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(auto v : adj[u]){
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
        // cycle is present
        if(count != V)
            return true;
        
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