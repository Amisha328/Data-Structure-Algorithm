// Shortest Path in Weighted undirected graph
// Problem link:
// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // {dist,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        vector<int> parent(n+1);
        vector<int> dist(n+1, 1e9);
        
        dist[1] = 0;
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        min_heap.push({0, 1});
        while(!min_heap.empty()){
            int dis = min_heap.top().first;
            int node = min_heap.top().second;
            min_heap.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                
                if(dist[adjNode] > dis + weight){
                    dist[adjNode] = dis + weight;
                    parent[adjNode] = node;
                    min_heap.push({dist[adjNode], adjNode});
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
