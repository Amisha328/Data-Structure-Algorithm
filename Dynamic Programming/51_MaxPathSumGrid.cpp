// Maximum Path Sum in the matrix
// Problem Statement: https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#
// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?leftPanelTab=0


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /* 
    //Memoization: TC-> O(N*M) + O(M) | SC -> O(N*M) + O(N)
    int dp[501][501];
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(j < 0 || j > grid[0].size()-1) return INT_MIN;
        if(i == 0) return grid[0][j];
        //if(i == 0 && j == 0) return grid[0][0];
        //if(i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size()-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int path1 = solve(grid, i-1, j);  // Down: (row+1,col)
        int path2 = solve(grid, i-1, j+1);  // Down left diagonal: (row+1,col-1)
        int path3 = solve(grid, i-1, j-1);  // Down right diagonal: (row+1, col+1)
        
        return dp[i][j] = grid[i][j] + max({path1, path2, path3});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        memset(dp, -1, sizeof(dp));
        int ans = INT_MIN;
        for(int j = 0; j < Matrix[0].size(); j++)
                ans = max(ans,solve(Matrix, Matrix.size()-1, j));
                
        return ans;
    }
    */
    
    /* 
    // Tabulation: TC->O(N*M) + O(N) | SC -> O(N*M)
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Base case in Memoization changed to Initialization in Tabulation
        for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int p1, p2, p3;
                p1 = p2 = p3 = INT_MIN;
                p1 = dp[i-1][j];
                if(j-1 >= 0) p2 = dp[i-1][j-1];
                if(j+1 < m) p3 = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + max({p1, p2, p3});
            }
        }

        int ans = dp[n-1][0];
        for(int j = 1; j < m; j++)
            ans = max(ans, dp[n-1][j]);

        return ans;
    }
    */

   // Space Optimization: TC-> O(N*M) | SC-> O(N)
   int maximumPath(int N, vector<vector<int>> matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0);
        // Base case in Memoization changed to Initialization in Tabulation
        for(int j = 0; j < m; j++) prev[j] = matrix[0][j];

        for(int i = 1; i < n; i++)
        {
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++)
            {
                int p1, p2, p3;
                p1 = p2 = p3 = INT_MIN;
                p1 = prev[j];
                if(j-1 >= 0) p2 = prev[j-1];
                if(j+1 < m) p3 = prev[j+1];

                curr[j] = matrix[i][j] + max({p1, p2, p3});
            }
            prev = curr;
        }

        int ans = INT_MIN;
        for(int j = 0; j < m; j++)
            ans = max(ans, prev[j]);

        return ans;
    }

};

int main(){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    return 0;
}

//Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N)