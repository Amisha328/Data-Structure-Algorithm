// Count Square Submatrices with all Ones
// Problem link:
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
// https://practice.geeksforgeeks.org/problems/count-square-submatrices-with-all-ones/1?
// https://www.codingninjas.com/codestudio/problems/count-square-submatrices-with-all-ones_3751502?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

// TC -> O(N X M) | SC -> O(N X M)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) dp[i][0] = matrix[i][0];
        for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum += dp[i][j];
            }
        }
        return sum;
    }
};