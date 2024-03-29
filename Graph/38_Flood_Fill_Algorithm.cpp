// Flood Fill Algorithm
// Problem link:
// https://leetcode.com/problems/flood-fill/
// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
// https://www.codingninjas.com/codestudio/problem-details/flood-fill-algorithm_1089687

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int newColor, int  initialColor,
            vector<vector<int>>& ans, vector<int> &delRow, vector<int> &delCol)
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++)
        {
                int r = row + delRow[i];
                int c = col + delCol[i];
            // check boundary
            // check if new cell has same color as statting pixel
            // check if cell is not already visited.
                if(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == initialColor && ans[r][c] != newColor)
                    dfs(image, r, c, newColor, initialColor, ans, delRow, delCol);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // storing the initial color as we can modify only those connected cell having same color as the starting pixel.
        int initialColor = image[sr][sc];
        // replica of the orginal matrix to mark the changes (visited)
        vector<vector<int>> ans = image;
        // To move in all the four directions
        vector<int> delRow = {-1, 0, +1, 0}; 
        vector<int> delCol = {0, +1, 0, -1};
        dfs(image, sr, sc, color, initialColor, ans, delRow, delCol);
        return ans;
    }
};