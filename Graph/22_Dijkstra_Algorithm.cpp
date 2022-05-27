// Implementing Dijkstra Algorithm 
// problem link: 
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// https://leetcode.com/problems/network-delay-time/
// More problems:
// https://leetcode.com/discuss/interview-question/731911/please-share-dijkstras-algorithm-questions

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    // TC-> O(V+E)logV | SC-> O(V)
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // By default, C++ creates a max-heap for priority queue.
        // min-heap ; In pair => (dist,from)
        // syntax: priority_queue <int, vector<int>, greater<int>> g = gq;  
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(V+1, INT_MAX);
        distance[S] = 0;
        pq.push({0,S});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for(auto it: adj[prev])
            {
                if(distance[it[0]] > distance[prev]+it[1]){
                    distance[it[0]] = distance[prev]+it[1];
                    pq.push({distance[it[0]], it[0]});
                }
            }
        }
        return distance;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
