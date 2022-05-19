// DFS of connected graph 
// Problem link:
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// https://leetcode.com/problems/keys-and-rooms/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[], int s, bool visited[], vector<int> &v)
    {
       if(visited[s] == false)
       {
           visited[s] = true;
            v.push_back(s);
            
            for(int u : adj[s])
            {
                if(visited[u] == false)
                {
                    dfs(adj, u, visited, v);
                }
            }
       }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> v;
        
        bool visited[V+1];
        
        for(int i = 0; i < V; i++)
            visited[i] = false;
        
        dfs(adj, 0, visited, v);
        
        return v;
    }
};

int main() {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    return 0;
} 