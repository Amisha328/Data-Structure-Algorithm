// Topological sort
// Problem link:
// https://practice.geeksforgeeks.org/problems/topological-sort/1#
// https://www.codingninjas.com/codestudio/problem-details/topological-sorting_973003
// https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	/*
          // DFS based solution
          // TC-> O(V+E) | SC-> O(V)
	void dfsTopoSort(int u, vector<int> adj[], vector<int> &visited, stack<int> &st)
	{
	    visited[u] = 1;
	    for(auto v : adj[u])
	    {
	        if(!visited[v])
	            dfsTopoSort(v, adj, visited, st);
	    }
	    st.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V, 0);
	    stack<int> st;
	    for(int i = 0; i < V; i++)
	    {
	        if(!visited[i])
	            dfsTopoSort(i, adj, visited, st);
	    }
	    
	    vector<int> topo;
	    while(!st.empty())
	    {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
	*/
	
          // BFS based solution - Kahn's Algorithm
          // TC-> O(V+E) | SC-> O(V)
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);
	    vector<int> topo;
	    // Store the indegree of all the nodes
	    for(int i = 0; i < V; i++)
	    {
	        for(auto x: adj[i])
	            indegree[x]++;
	    }
	    
	    queue<int> q;
	    
	    // Nodes with indegree zero push them into the stack
	    // bcz if indegree 0 then this node appears before then its adjacent
	    for(int i = 0; i < V; i++)
	    {
	        if(!indegree[i])
	            q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        // pop the element from the queue reduce the indegree of its adjacent nodes
	        // if it gets zero then push in queue;
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto v : adj[node])
	        {
	            if(--indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    return topo;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  