// Shortest Path in Undirected Graph with Unit Weights

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> shortedPath(vector<int> adj[], int src, int V)
{
          vector<int> distance(V, INT_MAX);
          queue<int> q;
          distance[src] = 0;
          q.push(src);
          while(!q.empty())
          {
               int u = q.front();
               q.pop();
               for(auto v: adj[u])
               {
                         if(distance[u]+1 < distnace[v])
                         {
                                   distance[v] = distance[u]+1;
                                   q.push(v);
                         }
               }
          }
          return distance;
}
