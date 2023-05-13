// Painting Fence
// Problem statement:
/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that 
at most 2 adjacent posts have the same color. Since the answer can be large return it modulo 10^9 + 7.
*/
// Problem link:
// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1?
// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?leftPanelTab=0


#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Memoization:
// TC -> O(N) | SC -> O(N) + O(N)
class Solution{
    private:
    long long f(int n, int k, vector<long long> &dp){
        if(n == 1) return k;
        if(n == 2) return (k + (k * (k-1))%MOD)%MOD;
        if(dp[n] != -1) return dp[n];
        int lastSame = (f(n-2, k, dp)%MOD * (k-1))%MOD;
        int lastDiff = (f(n-1, k, dp)%MOD * (k-1))%MOD;
    
        return dp[n] = (lastSame + lastDiff)%MOD;
    }
    public:
    long long countWays(int n, int k){
        vector<long long> dp(n+1, -1);
        return f(n, k, dp); 
    }
};

// Tabulation:
// TC -> O(N) | SC -> O(N)
#define MOD 1000000007
class Solution{
    public:
    long long countWays(int n, int k){
        vector<long long> dp(n+1, 0);
        dp[1] = k;
        dp[2] = (k + (k * (k-1))%MOD)%MOD;
        for(int i = 3; i <= n; i++){
            int lastSame = (dp[i -2]%MOD * (k-1))%MOD;
            int lastDiff = (dp[i-1]%MOD * (k-1))%MOD;
        
            dp[i] = (lastSame + lastDiff)%MOD;
        }
        return dp[n];
    }
};

// Space Optimization
// TC -> O(N) | SC -> O(1)
#define MOD 1000000007
class Solution{
    public:
    long long countWays(int n, int k){
        if(n == 1) return k;
        long long prev1 = k;
        long long prev2 = (k + (k * (k-1))%MOD)%MOD;
        
        for(int i = 3; i <= n; i++){
            long long ans = ((prev1 * (k-1))%MOD + (prev2 * (k-1))%MOD)%MOD;
            prev1 = prev2;
            prev2 = ans;
        }
        return prev2;
    }
};