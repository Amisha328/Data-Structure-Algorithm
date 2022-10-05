// Replace ‘O’ With ‘X’
// Problem link:
// https://leetcode.com/problems/surrounded-regions/
// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
// https://www.codingninjas.com/codestudio/problem-details/replace-o-with-x_630517

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(vector<vector<char>>& mat, vector<vector<char>>&  vist, int row, int col, vector<int> &delRow, vector<int> &delCol)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        // we will run through all the unvisited neighboring ‘O’s in all 4 directions 
        // and mark them as visited so that they are not converted to ‘X’ in the future.
        
        vist[row][col] = 1;
        for(int i = 0; i < 4; i++)
        {
            int r = row + delRow[i];
            int c = col + delCol[i];
            if(r >= 0 && r < n && c >= 0 && c < m && !vist[r][c] && mat[r][c] == 'O')
                dfs(mat, vist, r, c, delRow, delCol);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> vist(n, vector<char>(m, 0));
        // four directions
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        // traverse first row and last row
        for(int c = 0; c < m; c++)
        {
            // first row
            if(!vist[0][c] && mat[0][c] == 'O')
                dfs(mat, vist, 0, c, delRow, delCol);
            // last row
            if(!vist[n-1][c] && mat[n-1][c] == 'O')
                dfs(mat, vist, n-1, c, delRow, delCol);
        }
        
        // traverse the left most and right most boundary
        for(int r = 0; r < n; r++)
        {
            // left-most boundary
            if(!vist[r][0] && mat[r][0] == 'O')
                dfs(mat, vist, r, 0, delRow, delCol);
            // right-most boundary
            if(!vist[r][m-1] && mat[r][m-1] == 'O')
                dfs(mat, vist, r, m-1, delRow, delCol);
        }
        // When all the boundaries are traversed and corresponding sets of ‘O’s are marked as visited,
        // they cannot be replaced with ‘X’.
        // All the other remaining unvisited ‘O’s are replaced with ‘X’.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vist[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
                    
            }
        }
        return mat;
    }
};

/*
Time Complexity: O(NxMx4) ~ O(N x M)
DFS function will be called for (N x M) and for every cell, we are traversing for 4 neighbors, so it will take O(N x M x 4) time.
Space Complexity: O(N x M) for the visited array
*/