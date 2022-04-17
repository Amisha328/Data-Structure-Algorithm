// Unique Paths
// Problem statement: https://leetcode.com/problems/unique-paths/
// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /*
    // Memoization: TC->O(m*n) | SC-> O(m*n) + O((m-1)(n-1))
    int dp[101][101];
    int solve(int i, int j)
    {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i-1, j);
        int left = solve(i, j-1);
        
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(m-1, n-1);
    }
    */
    
    /*
    // Tabulation: TC -> O(m*n) | SC-> O(m*n)
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left; 
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    */
    
    // Space Optimization: TC->O(n*m) | SC-> O(n)
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for(int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    temp[j] = 1;
                else
                {
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = temp[j-1];
                    temp[j] = up + left;
                }
            }
            
            prev = temp;
        }
    
    return prev[n-1];
    
    }
};

int main() {
        int m,n;
        cin >> m >> n;
        Solution ob;
        cout << ob.uniquePaths(m, n)<< endl;
    return 0;
} 