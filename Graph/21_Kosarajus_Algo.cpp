// Kosaraju's Algorithm for Strongly Connected Components (SCC)
// Problem link: 
// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/

// TC-> O(N + E) | SC-> O(N+E + O(N) + O(N)
#include<bits/stdc++.h>
using namespace std;
class Solution
{
       public:
       //Function to find number of strongly connected components in the graph.
       void dfs(int u, vector<int> G[], vector<bool> &visited, stack<int> &s, bool topo)
       {
          visited[u] = true;
          for(auto &v: G[u])
                    if(!visited[v])
                    dfs(v, G, visited, s, topo);
          if(topo)
                    s.push(u);
    
       }
       int kosaraju(int V, vector<int> G[])
       {
          vector<int> RG[V];
          stack<int> s;
          vector<bool> visited(V, false);
          
                    // Step 1: Store vertices in Topological Sort order
                    for(int u=0;u<V;u++)
                              if(!visited[u])
                              dfs(u, G, visited, s, true);
          
                    // Step 2: Reverse all edges of the Graph
                    for(int u=0;u<V;u++)
                              for(auto &v: G[u])
                                        RG[v].push_back(u);
          
                    visited = vector<bool>(V, false);
                    
                    // Step 3: One by One pop elements from top of the stack and Count/Store and Mark the elements visited by current vertex
                    int scc = 0;
                    while(!s.empty())
                    {
                              auto u = s.top();
                              s.pop();
                              if(!visited[u]){
                                        dfs(u, RG, visited, s, false);
                                        scc++;
                              }
                    } 
          return scc;
       }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
