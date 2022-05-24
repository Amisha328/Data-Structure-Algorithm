// Shortest Path in Directed Acyclic Graph
// Using Topological Sort

#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int src, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &s)
{
          visited[src] = 1;
          for(auto node : adj[src])
                    if(!visited[node.first])
                          topologicalSort(node.first, adj, visited, s);
          s.push(src);    
}

void shortestPathDAG(int src, vector<pair<int, int>> adj[], int n){
          vector<int> visited(n, 0);
          stack<int> s;
          for(int i = 0; i < n; i++){
                    if(!visited[i])
                        topologicalSort(i, adj, visited, s);      
          }

          vector<int> dis(n, INT_MAX);
          dis[src] = 0;
          while(!s.empty())
          {
                    int u = s.top();
                    s.pop();
                    if(dis[u] != INT_MAX)
                    {
                              for(auto v: adj[u])
                              {
                                        if(dis[v.first] > dis[u]+v.second)
                                                  dis[v.first] = dis[u] + v.second;
                              }
                    }
          }
          for(auto it: dis)
                    cout<<it<<" ";
}
int main()
{
          int n, m;
          cin>> n>> m;
          vector<pair<int, int>> adj[n];
          for(int i = 0; i < m; i++)
          {
                    int u, v, wt;
                    cin>>u>>v>>wt;
                    adj[u].push_back({v,wt});
          }
          shortestPathDAG(0, adj, n);
}

// Test Case
// 6 7
// 0 1 2
// 0 4 1
// 1 2 3
// 2 3 6
// 4 2 2
// 4 5 4
// 5 3 1