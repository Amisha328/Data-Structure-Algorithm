// Minimum Spanning Tree -  Kruskal's Algorithm
// Using Disjoin Set to find MST
// Problem link: 
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#
// https://leetcode.com/problems/redundant-connection/

#include<bits/stdc++.h>
using namespace std;
// TC-> O(ElogE) || SC-> O(V)
struct node
{
    public:
    int u, v, wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};
class Solution
{
    int findPar(int u, vector<int> &parent) {
        if(u == parent[u]) return u; 
        // path compression
        return parent[u] = findPar(parent[u], parent); 
    }
    
    void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findPar(u, parent);
        v = findPar(v, parent);
        if(rank[u] < rank[v]) {
        	parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
        	parent[v] = u; 
        }
        else { // attach any to any and just inc the rank of node to which attached
        	parent[v] = u;
        	rank[u]++; 
        }
    }
    static bool cmp(node &a, node &b){
        return a.wt < b.wt;
    }
    public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int cost = 0;
        vector<int> rank(V, 0);
        vector<int> parent(V);
        vector<pair<int,int>> mstSet;
        for(int i = 0; i < V; i++)
            parent[i] = i;
            
            
        vector<node> edges;
        for(int i = 0; i < V; i++){
            for(auto vec: adj[i]){
                edges.push_back(node(i, vec[0], vec[1]));
            }
        }
    
            
        sort(edges.begin(), edges.end(), cmp);
      
        for(auto it: edges){
            if(findPar(it.u,parent) != findPar(it.v,parent)){
                mstSet.push_back(make_pair(it.u,it.v));
                unionn(it.u, it.v, parent, rank);
                cost += it.wt;
            }
        }
        return cost;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends