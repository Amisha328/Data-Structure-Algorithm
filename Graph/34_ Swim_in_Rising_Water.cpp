// Swim in Rising Water
// Problem link: 
// https://leetcode.com/problems/swim-in-rising-water/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Using Priority Queue (Min-Heap)
    bool isValid(int x, int y, int n){
        return (x >= 0 && x < n && y >= 0 && y < n);
    }
    bool exist(vector<pair<int, int>> &visit, int r, int c){
        for(auto &it: visit){
            if(it.first == r && it.second == c)
                return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> dist = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<pair<int, int>> visit; // r, c
        // min-heap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // time, r, c
        pq.push({grid[0][0],0,0});
        visit.push_back({0,0});
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            int t = u[0];
            int r = u[1];
            int c = u[2];
            if(r == n-1 && c == n-1) return t;
            for(int i = 0; i < 4; i++){
                // check for all four directions adjacent cells
                int adj_r = r + dist[i].first;
                int adj_c = c + dist[i].second;
                // if cell is valid and,
                // not already visited
                if(isValid(adj_r, adj_c, n) && !exist(visit, adj_r, adj_c)){
                        visit.push_back({adj_r, adj_c});
                        pq.push({max(t,grid[adj_r][adj_c]),adj_r, adj_c});
                    }
            }
        }
        return 0;
    }
    */

   // Using Binary Search 

    // 4-directionally adjacent square
   vector<pair<int, int>> dist = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // check if within the boundaries of the grid 
    bool isValid(int x, int y, int n){
        return (x >= 0 && x < n && y >= 0 && y < n);
    }
    bool isReachable(int t, vector<vector<int>>& grid, int n, int r, int c, vector<vector<bool>> &visit)
    {
        if(r == n-1 && c == n-1)
            return true;
        visit[r][c] = true;
        for(int i = 0; i < 4; i++){
            int adj_r = r + dist[i].first;
            int adj_c = c + dist[i].second; 
            if(isValid(adj_r, adj_c, n) && !visit[adj_r][adj_c] && grid[r][c] <= t && grid[adj_r][adj_c] <= t){
                if(isReachable(t, grid, n, adj_r, adj_c, visit))
                    return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Since Each value grid[i][j] is unique
        // Binary Seach range is from 0 to n*n-1 for value least value of time
        int l = 0, h = n*n-1;
        while(l < h){
            int mid = (l+h)>>1;
            vector<vector<bool>> visit(n, vector<bool> (n, false));
            if(isReachable(mid, grid, n, 0, 0, visit))
                h = mid;  // even (n-1,n-1) rechable we set h = mid to check if any lower value than this exist with which (n-1, n-1) can be reached
            else
                l = mid+1;
        }
        return l;
    }
};
    
    