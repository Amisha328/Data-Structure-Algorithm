// Unique Path with obstacles
// Problem link: https://leetcode.com/problems/unique-paths-ii/
// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    // Memoization
    int dp[101][101];
    int solve(vector<vector<int>>& arr, int i, int j)
    {
        if( i >= 0 && j >= 0 && arr[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = 0, left = 0;
        up = solve(arr, i-1, j);
        left = solve(arr, i, j-1);
        
        return dp[i][j] = up + left;
          
    }
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();
       // memset(dp, -1, sizeof(dp));
       // return solve(obstacleGrid, m-1, n-1);
        /*
       // Tabulation
       int dp[m][n];
       for(int i = 0; i < m; i++)
       {
            for(int j = 0; j < n; j++)
            {
                if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1 )
                    dp[i][j] = 0;
                else if(i == 0 && j == 0)
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
        */
        
        vector<int> prev(n, 0);
        for(int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++)
            {
                if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1 )
                    temp[j] = 0;
                else if(i == 0 && j == 0)
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
        vector<vector<int>> v(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin>>v[i][j];
        Solution ob;
        cout << ob.uniquePathsWithObstacles(v)<< endl;
    return 0;
} 