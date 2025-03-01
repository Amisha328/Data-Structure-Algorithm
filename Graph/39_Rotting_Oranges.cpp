// Rotting Oranges
// Problem link:
// https://leetcode.com/problems/rotting-oranges/
// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
// https://www.codingninjas.com/codestudio/problems/rotting-oranges_701655

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        // {{row, col}, time}
        queue<pair<pair<int,int>,int>> q;
        int cntFresh = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    // rotten all the valid fresh orange neighbours and
                    // puts them in the queue with initial time as 0 units.
                    q.push({{i,j},0});
                    visited[i][j] = 2; // mark it as rotten in the visited array.  
                }
                else visited[i][j] = 0; // mark it not visited
                
                if(grid[i][j] == 1) cntFresh++; // count the number of fresh oranges in the grid
            }
        }
        
        int max_time = 0;
        vector<int> delRow = {-1, 0, +1, 0}; 
        vector<int> delCol = {0, +1, 0, -1};
        int cnt = 0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            max_time = max(max_time, time);
            for(int i = 0; i < 4; i++)
            {
                int r = row + delRow[i];
                int c = col + delCol[i];
                // check boundary
                // check if cell is already visisted
                // check if the cell contains fresh orange
                if(r >= 0 && r < n && c >= 0 && c < m && visited[r][c] == 0 && grid[r][c] == 1)
                {
                    // rotten all the valid fresh orange neighbours and
                    // puts them in the queue with an increasing time by 1 unit.
                    q.push({{r,c},time+1});  
                    visited[r][c] = 2; // mark it as rotten in the visited array.
                    cnt++; // counts to check all the fresh oranges are visited
                }
            }
        }
        
        if(cnt != cntFresh) return -1;
        return max_time;
    }
};