// Number of Enclaves
// Problem link:
// https://leetcode.com/problems/number-of-enclaves/
// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

#include <bits/stdc++.h>
using namespace std;

// DFS

class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vist, int row, int col, vector<int>& delRow, vector<int> &delCol)
    {
        int n = grid.size();
        int m = grid[0].size();
        vist[row][col] = 1;
        for(int i = 0; i < 4; i++)
        {
            int r = row + delRow[i];
            int c = col + delCol[i];
            if(r >= 0 && r < n && c >= 0 && c < m && !vist[r][c] && grid[r][c] == 1)
                dfs(grid, vist, r, c, delRow, delCol);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
		// four directions
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        vector<vector<int>> vist(n, vector<int>(m, 0));
     
        // DFS
		
		// traverse first row and last row
        for(int c = 0; c < m; c++)
        {
		    // first row
            if(!vist[0][c] && grid[0][c] == 1)
                dfs(grid, vist, 0, c, delRow, delCol);
			// last row
            if(!vist[n-1][c] && grid[n-1][c] == 1)
                dfs(grid, vist, n-1, c, delRow, delCol);
        }
		// traverse the left most and right most boundary
        for(int r = 0; r < n; r++)
        {
			// left-most boundary
            if(!vist[r][0] && grid[r][0] == 1)
                dfs(grid, vist, r, 0, delRow, delCol);
		   // right-most boundary
            if(!vist[r][m-1] && grid[r][m-1] == 1)
                dfs(grid, vist, r, m-1, delRow, delCol);
        }
		// When all the boundaries are traversed and corresponding sets of ‘1’s are marked as visited,
        // All the other remaining unvisited ‘1’s cannot walk off the boundary of the grid
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vist[i][j] && grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
		}
};

// BFS

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        vector<vector<int>> vist(n, vector<int>(m, 0));
		// BFS
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                    if(!vist[i][j] && grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vist[i][j] = 1;
                    }
                    
                }
            }
        }
       
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int r = row + delRow[i];
                int c = col + delCol[i];
                if(r >= 0 && r < n && c >= 0 && c < m && !vist[r][c] && grid[r][c] == 1)
                {
                    q.push({r, c});
                    vist[r][c] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vist[i][j] && grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};