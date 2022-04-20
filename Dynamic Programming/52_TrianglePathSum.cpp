// Triangle Problem
// Problem link: https://leetcode.com/problems/triangle/
// https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /*
    // Memoization: TC-> O(n * n) | SC-> O(n)[recursion stack space] + O(n * n) [dp 2-D matrix space]
    int dp[201][201];
    int solve(vector<vector<int>>& triangle, int i, int j)
    {
        int n = triangle.size();
        
        if(i == n-1) return triangle[n-1][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = solve(triangle, i+1, j);
        int diag = solve(triangle, i+1,j+1);
        
        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(triangle, 0, 0);
    }
    */
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        
        /* 
        // Tabulation: TC-> O(n * n) | SC-> O(n * n) [dp 2-D matrix space]
          // Note: Tabulation goes opposite to Memoization.
        vector<vector<int>> dp(n, vector<int> (n,0));
        
        // Base case changed to inilialization
        for(int j = 0; j < n; j++)
            dp[n-1][j] = triangle[n-1][j];
        
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int down = dp[i+1][j];
                int diag = dp[i+1][j+1];
                
                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }
        
        return dp[0][0];
        */
        
        // Space Optimization: TC-> O(n * n) | SC-> O(n)
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++)
            temp[j] = triangle[n-1][j];
        
        for(int i = n-2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            for(int j = i; j >= 0; j--)
            {
                int down = temp[j];
                int diag = temp[j+1];
                
                curr[j] = triangle[i][j] + min(down, diag);
            }
            
            temp = curr;
        }
        
        return temp[0];
    }
    
};

int main(){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.minimumTotal(Matrix)<<"\n";
    return 0;
}

