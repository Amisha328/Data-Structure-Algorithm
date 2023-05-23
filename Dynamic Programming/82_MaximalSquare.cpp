// Maximal Square
// Problem link:
// https://leetcode.com/problems/maximal-square/description/
// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1?
// https://www.codingninjas.com/codestudio/problems/maximum-area-square_981268?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

// Memoization:
// TC-> O(N X M) | SC-> O(N X M) + O(N X M)
class Solution{
private:
    int f(vector<vector<int>>& matrix, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = f(matrix, i, j+1, maxi, dp);
        int diagonal = f(matrix, i+1, j+1, maxi, dp);
        int down = f(matrix, i+1, j, maxi, dp);
        
        if(matrix[i][j] == 1){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
           // return dp[i][j] = max(dp[i][j], 1 + min(right, min(diagonal, down)));
        }
        return dp[i][j] = 0;
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        f(mat, 0, 0, maxi, dp);
        return maxi;
    }
};

// Tabulation:
// TC-> O(N X M) | SC-> O(N  X M)
class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return maxi;
    }
};

// Space Optimization:
// TC-> O(N X M) | SC-> O(M)
class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        vector<int> curr(m+1, 0), next(m+1, 0);
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int right = curr[i];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else curr[j] = 0;
            }
            next = curr;
        }
        return maxi;
    }
};