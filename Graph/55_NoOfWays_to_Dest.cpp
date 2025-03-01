// Number of Ways to Arrive at Destination
// Problem link:
// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<pair<int, int>> adj[n];
       for(auto it: roads)
       {
           adj[it[0]].push_back({it[1], it[2]});
           adj[it[1]].push_back({it[0], it[2]});
       }
       
       priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
       vector<long long> dist(n, LONG_MAX), ways(n, 0);
       
       dist[0] = 0;
       ways[0] = 1;
       
       pq.push({0, 0});
       
       int mod = (int) (1e9 + 7);
       while(!pq.empty())
       {
           long long dis = pq.top().first;
           long long node = pq.top().second;
           pq.pop();
           
           for(auto iter: adj[node])
           {
               long long adjNode = iter.first;
               long long edgW = iter.second;
               
               // If I am comming for the first time on this node with this smaller distance
               if(dis + edgW < dist[adjNode])
               {
                   dist[adjNode] = dis + edgW;
                   pq.push({dis + edgW, adjNode});
                   ways[adjNode] = ways[node];
               }
               // If I have come to this node with this distance before then just update the ways
               else if(dis + edgW == dist[adjNode]){
                   ways[adjNode] += ways[node]%mod;
               }
           }
       }
       return ways[n-1]%mod;
    }
};