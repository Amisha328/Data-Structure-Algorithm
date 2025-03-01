// Min Score Triangulation of Polygon
// Problem link:
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

#include<bits/stdc++.h>
using namespace std;

// Memoization
// TC -> O(N ^ 3) | SC -> O(N^2) + stack space
class Solution {
private:
    int f(vector<int> &values, int i, int j, vector<vector<int>> &dp){
        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++){
            ans = min(ans, values[i]*values[j]*values[k] + f(values, i, k, dp) + f(values, k, j, dp));
        }
        return dp[i][j] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(values, 0, n-1, dp);
    }
};


// Tabulation
// TC-> O(N ^ 3) | SC -> O(N ^ 2)

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = i+2; j < n; j++){ //j can't be i and i+1 as it will be one or 2 points and if j = i+2 then we have atleast 3 points. 
                int ans = INT_MAX;
                for(int k = i+1; k < j; k++){
                    ans = min(ans, values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
};