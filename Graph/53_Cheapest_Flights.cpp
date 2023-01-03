// Cheapest Flights Within K Stops
// Problem link:
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // initialize the adjacency list, distance and queue
        vector<pair<int, int>> adj[n];
        vector<int> dis(n, 1e9);
        queue<vector<int>> q;
        
        // make the adjacency list
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // push the src node to the queue
        q.push({0, src, 0});
        // mark the distance as 0 (i.e it is the first element)
        dis[src] = 0;
        
        // until queue is empty do the operation
        while(!q.empty()){
            // take the first element of the queue
            auto it = q.front();
            int stop = it[0];
            int node = it[1];
            int cost = it[2];
            q.pop();
            
            // if we reach destination with k+1 move then stop 
            // iteration as we reached destination with atmost 
            // k stops 
            if(stop > k) continue;
            
            // check all its adjacent edges
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int weight = iter.second;
                
                if(cost + weight < dis[adjNode]) {
                    dis[adjNode] = cost + weight;  // update the distance 
                    q.push({stop+1, adjNode, cost + weight});  // push the adj element and new distance into queue
                }
            }
        }
        
        // if the distance of the dst is not changed the return -1
        // as it is not possible to reach destination
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};