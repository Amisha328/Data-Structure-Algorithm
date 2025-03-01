// Path With Minimum Effort
// Problem link:
// https://leetcode.com/problems/path-with-minimum-effort/
// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?
// https://www.codingninjas.com/codestudio/problem-details/path-with-minimum-effort_1380958

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
                
            if(row == n-1 && col == m-1) return diff;
            
            for(int i = 0; i < 4; i++){
                int newR = row + delRow[i];
                int newC = col + delCol[i];
                
                if(newR >= 0 && newR < n && newC >= 0 && newC < m){
                    int newEffort = max(abs(heights[row][col] - heights[newR][newC]), diff);
                    if(newEffort < dist[newR][newC]){
                        dist[newR][newC] = newEffort;
                        pq.push({newEffort, {newR, newC}});
                    }                         
                }
            }
        }
        return 0;
    }
};