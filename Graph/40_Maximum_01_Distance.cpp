// Maximum 0-1 Distance
// Problem link:
// https://leetcode.com/problems/01-matrix/
// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
// https://www.codingninjas.com/codestudio/problem-details/maximum-0-1-distance_920459

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>> q;
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({{i,j}, 0});
	                vis[i][j] = 1;
	            }
	            else
	                vis[i][j] = 0;
	        }
	    }
	    
	    vector<int> delRow = {-1, 0, +1, 0};
	    vector<int> delCol = {0, +1, 0, -1};
	    while(!q.empty())
	    {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int step = q.front().second;
	        q.pop();
	        dist[row][col] = step;
	        for(int i = 0; i < 4; i++)
	        {
	            int r = row + delRow[i];
	            int c = col + delCol[i];
	            if(r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 0)
	            {
	                q.push({{r, c}, step+1});
	                vis[r][c] = 1;
	            }
	        }
	    }
	    return dist;
	}
};