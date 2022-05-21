// Check Bipartite Graph using DFS
// Problem link:
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1/#
// https://leetcode.com/problems/is-graph-bipartite/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool dfsCheck(vector<int> adj[], int node, vector<int> &color)
{
    if(color[node] == -1)
        color[node] = 1;
    
    for(auto u: adj[node])
    {
        if(color[u] == -1)
        {
            color[u] = 1 - color[node];
            if(!dfsCheck(adj, u, color))
                return false;
        }
        else if(color[u] == color[node])
            return false;
    }
    return true;
}
    bool isBipartite(int V, vector<int>adj[])
    {	 
	vector<int> color(V, -1);
	for(int i = 0; i < V; i++)
	{
	  if(color[i] == -1)
            {
                if(!dfsCheck(adj, i, color))
                    return false;
            }
	}
	return true;
     }

};

int main(){
	
	int V, E;
	cin >> V >> E;
	vector<int>adj[V];
	for(int i = 0; i < E; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Solution obj;
	bool ans = obj.isBipartite(V, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	return 0;
} 