// City With the Smallest Number of Neighbors at a Threshold Distance
// Problem link:
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?

#include <bits/stdc++.h>
using namespace std;

// Floyd Warshall
// TC -> O(n^3) | SC-> O(n^2)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto &it: edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        
        // Applying Floyd Warshall algorithm
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        for(int k = 0; k < n; k++){
	        for(int i = 0; i < n; i++){
	            for(int j = 0; j < n; j++){
	                if(i == j || dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) 
	                    continue;
	               
	                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	            }
	        }
	    }
        
       int cntCity = n;
        int cityNo = -1;
        for(int city = 0; city < n; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity < n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }
            // Return the city with the smallest number of neighbours
            if(cntCity >= cnt){
                cntCity = cnt;
                cityNo = city; // return the city with the greatest number
            }
        }
        return cityNo;
    }
};

// Dijkstra Algorithm
// TC-> O(V * (ElogV))

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<pair<int,int>> adj[n];
        for(auto &it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // Applying Dijkstra algorithm
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < n; i++)
        {
            pq.push({0, i});
            while(!pq.empty())
            {
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                for(auto &it: adj[node]){
                    if(it.second + dis < dist[i][it.first]){
                        dist[i][it.first] = it.second + dis;
                        pq.push({it.second + dis, it.first});
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }
        
        int cntCity = n;
        int cityNo = -1;
        for(int city = 0; city < n; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity < n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }
            // Return the city with the smallest number of neighbours
            if(cntCity >= cnt){
                cntCity = cnt;
                cityNo = city; // return the city with the greatest number
            }
        }
        return cityNo;
    }
};