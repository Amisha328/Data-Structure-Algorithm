// Out of Boundary Paths
// Problem link: https://leetcode.com/problems/out-of-boundary-paths/

#include<bits/stdc++.h>
class Solution {
public:
    // Memoization
    int mod = 1000000007;
    int solve(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &dp){
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n) return 1;
        if(maxMove == 0) return 0;
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        dp[startRow][startColumn][maxMove] = ((solve(m, n, maxMove-1, startRow-1, startColumn, dp) + solve(m, n, maxMove-1, startRow, startColumn-1, dp))%mod + (solve(m, n, maxMove - 1, startRow+1, startColumn, dp) + solve(m, n, maxMove - 1, startRow, startColumn+1, dp))%mod) % mod ;
        return dp[startRow][startColumn][maxMove];
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};