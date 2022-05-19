// DFS of disconnected graph 
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/dfs-traversal_630462


#include <bits/stdc++.h>
using namespace std;

 void dfs(int node, vector<int> &vis, vector<int> adjM[], vector<int> &dfsOutput) {
    dfsOutput.push_back(node);
    vis[node] = 1; 
    
    //traversing the adjacent vertex.
    for(auto it: adjM[node]) {
        if(!vis[it]) {
            dfs(it, vis, adjM, dfsOutput); //recursive call
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // this graph is actually our adjancy matrix.
	vector<int> adj[V];
	for(int i=0;i<E;i++){
                    adj[edges[i][0]].push_back(edges[i][1]);
                    adj[edges[i][1]].push_back(edges[i][0]);
          }
    vector<vector<int>> DFS; // store the dfs traversal output of all component
    vector<int> vis(V, 0);
    
    for(int i=0; i<V;i++) 
	{
        if(!vis[i]) 
		{
        	vector<int> dfsOutput; // store the dfs traversal output of 
            dfs(i, vis, adj, dfsOutput);  //funcn call
			sort(dfsOutput.begin(), dfsOutput.end());
            DFS.push_back(dfsOutput);
        }
    }
    return DFS;
} 