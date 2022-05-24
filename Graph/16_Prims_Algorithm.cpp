// Minimum Spanning Tree -  Prim's Algorithm
// Problem link: 
// https://leetcode.com/problems/min-cost-to-connect-all-points/
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#
// https://www.codingninjas.com/codestudio/problem-details/prim-s-mst_1095633

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V, -1);
        vector<bool> mst(V, false);
        vector<int> key(V, INT_MAX);
        
        key[0] = 0;
        parent[0] = -1;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0,0}); // pair => (dis value, node) ; dis value for node 0 is 0.
        
     
        while(!pq.empty())
        {
            int u = pq.top().second; // node with min value is at the top
            pq.pop();
            
            mst[u] = true;
            for(auto it: adj[u])
            {
                int v = it[0];
                int wt = it[1];
                if(mst[v] == false && wt < key[v])
                {
                    key[v] = wt;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        
        int sum = accumulate(key.begin(), key.end(), 0LL);
        return sum;
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
