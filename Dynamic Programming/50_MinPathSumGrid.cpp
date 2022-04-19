// Minimum Path Sum in Grid
// Problem statement: https://leetcode.com/problems/minimum-path-sum/
// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    // Memoization:
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(grid, i-1, j);
        int left = solve(grid, i, j-1);
        
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, n-1, m-1);
    }
    */
    
    /* // Tabulation:
     int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else
                {
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = min(up, dp[i - 1][j]);
                    if(j > 0) lt5eft = min(left, dp[i][j - 1]);

                    dp[i][j] = min(up, left) + grid[i][j];
                }
            }
        }
         
         return dp[n-1][m-1];
         */
        
        // Space Optimization
        int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            
            vector<int> prev(m, 0);
            for(int i = 0; i < n; i++)
            {
                vector<int> curr(m, 0);
                for(int j = 0; j < m; j++)
                {
                    if(i == 0 && j == 0) curr[j] = grid[0][0];
                    else
                    {
                        int up = INT_MAX, left = INT_MAX;
                        if(i > 0) up = min(up, prev[j]);
                        if(j > 0) left = min(left, curr[j - 1]);

                        curr[j] = min(up, left) + grid[i][j];
                    }
                }
                prev = curr;
            }
            
            return prev[m-1];
     }
};

int main() {
        
        int m,n;
        cin >> m >> n;
        vector<vector<int>> v(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin>>v[i][j];
        Solution ob;
        cout << ob.minPathSum(v)<< endl;
    return 0;
} 