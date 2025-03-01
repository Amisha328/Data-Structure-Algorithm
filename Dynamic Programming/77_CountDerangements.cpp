// Count derangements
// Problem link:
// https://practice.geeksforgeeks.org/problems/dearrangement-of-balls0918/1?
// https://www.codingninjas.com/codestudio/problem-details/count-derangements_873861

#define MOD 1000000007

#include<bits/stdc++.h>
using namespace std;

// Memoization
// TC-> O(N) | SC-> O(N) + O(N)
class Solution{
private:
    long int f(int n, vector<long int> &dp){
        if(n == 1) return 0;
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (n-1)%MOD * (f(n-1, dp)%MOD + f(n-2, dp)%MOD)%MOD;
    }
public:
    long int disarrange(int N){
        vector<long int> dp(N+1, -1);
        return f(N, dp);
    }
};

// Tabulation:
// TC-> O(N) | SC-> O(N)
class Solution{public:
public:      
    long int disarrange(int N){
        vector<long int> dp(N+1, 0);
        dp[2] = 1;
        for(int i = 3; i <= N; i++){
            dp[i] = (i-1)%MOD * (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
        }
        return dp[N];
    }
};

// Space Optimization:
// TC-> O(N) | SC-> O(1)
class Solution{public:
public:      
    long int disarrange(int N){
        long int prev1 = 0;
        long int prev2 = 1;
        for(int i = 3; i <= N; i++){
            int ans = ((i-1)%MOD * (prev1 + prev2)%MOD)%MOD;
            prev1 = prev2;
            prev2 = ans;
        }
        return prev2;
    }
};