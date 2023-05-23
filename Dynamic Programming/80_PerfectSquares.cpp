// Perfect Squares | Get Minimum Squares
// Problem link:
// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1
// https://leetcode.com/problems/perfect-squares/description/

#include<bits/stdc++.h>
using namespace std;

// Memoization
// TC -> O(N X sqrt(N)) | SC -> O(N) + O(N)
class Solution {
private:
    int f(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = n;
        for(int i = 1; i * i <= n; i++){
            ans = min(ans, 1 + f(n - i*i, dp));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};


// Tabulation
// TC -> O(N X sqrt(N)) | SC -> O(N)
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int j = 1; j <= n; j++){
            for(int i = 1; i * i <= n; i++){
                if(j - i*i >= 0) dp[j] = min(dp[j], 1 + dp[j - i*i]);
            }
        }
        return dp[n];
    }
};