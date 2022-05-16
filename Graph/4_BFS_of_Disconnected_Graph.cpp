// BFS of disconnected graph 
// Problem link:
// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002
// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = 1;
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
           }
       }
        return bfs;
}
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
		vector<int> adj[V];

		for(auto x: edges){
			adj[x.first].push_back(x.second);
			adj[x.second].push_back(x.first);
		}
		for(int i = 0; i < V; i++)
		   sort(adj[i].begin(),adj[i].end());

		return bfsOfGraph(V, adj);
}