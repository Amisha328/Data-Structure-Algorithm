// Minimum Spanning Tree -  Kruskal's Algorithm
// Using Disjoin Set to find MST
// Problem link: 
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#
// https://leetcode.com/problems/redundant-connection/
// https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?leftPanelTab=0

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

// Another way to write the same code
// SC -> O(M)
class DisjointSet{
          vector<int> sizes, parent;
          public:
          DisjointSet(int n){
                    sizes.resize(n+1, 1);
                    parent.resize(n+1);
                    for(int i = 0; i <= n; i++)
                              parent[i] = i;
          }

          int findPar(int node){
                    if(node == parent[node]) return node;
                    return parent[node] = findPar(parent[node]);
          }
          void unionBySize(int u, int v){
                    int ulp_u = findPar(u);
                    int ulp_v = findPar(v);
                    if(ulp_u == ulp_v) return;
                    if(sizes[ulp_u] < sizes[ulp_v]){
                              parent[ulp_u] = ulp_v;
                              sizes[ulp_v] += sizes[ulp_u];
                    } else {
                              parent[ulp_v] = ulp_u;
                              sizes[ulp_u] += sizes[ulp_v];
                    }
          }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<pair<int, pair<int, int>>> edges; 
        // O(N + M)
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                edges.push_back({it[1], {i, it[0]}});
            }
        }
        
        sort(edges.begin(), edges.end()); // O(M log M)
        DisjointSet ds(V);
        int mstCost = 0;
        // O(M * 4 * alpha)
        for(auto it: edges){
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if(ds.findPar(u) != ds.findPar(v)){
              mstCost += w;
              ds.unionBySize(u, v);
            }
         }
         return mstCost;
    }
};
