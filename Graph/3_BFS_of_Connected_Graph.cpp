// BFS of connected graph 
// Problem link:
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
          vector<int> bfs;
          vector<int> visited(V, 0);
          queue<int> q;
          q.push(0);
          visited[0] = 1;
          while(!q.empty())
          {
              int node = q.front();
              q.pop();
              bfs.push_back(node);
                    
              for(auto x: adj[node])
              {
                    if(!visited[x])
                    {
                            q.push(x);
                            visited[x] = 1;
                    }
              }
          }
          return bfs;
}
int main()
{
	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
          //        adj[v].push_back(u); // uncomment this for undirected graoh 
    	}
        Solution obj;
        vector<int>ans = obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
    return 0;
}  