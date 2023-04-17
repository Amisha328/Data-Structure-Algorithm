// Matrix Chain Multiplication
// problem statement: 
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// https://www.codingninjas.com/codestudio/problem-details/matrix-chain-multiplication_975344

#include <bits/stdc++.h>
using namespace std;

// Memoization
// SC -> O(N X N) X O(N) | TC -> O(N X N) + O(n)
class Solution{
public:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr, int N)
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(1, N-1, arr, dp);
    }
};


// Tabulation
// SC -> O(N X N) X O(N) | TC -> O(N X N)

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for(int i = N-1; i >= 1; i--){
        for(int j = i+1; j < N; j++){
            int mini = 1e9;
            for(int k = i; k < j; k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}