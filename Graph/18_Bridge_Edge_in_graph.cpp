// Bridge edge in a graph
// problem link: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node, vector<int> adj[], int c, int d, vector<int> &visited){
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it] && (node != c || it != d))
                dfs(it, adj, c, d, visited);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> visited(V, 0);
        dfs(c, adj, c, d, visited);
        // if d visited  i.e it can be reached with some other path as well apart from throught c
        // hence, it can't be bridges
        return !visited[d];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}
