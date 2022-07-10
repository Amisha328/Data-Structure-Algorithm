// Min Cost Climbing Stairs
// Problem link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
class Solution {
public:
    /*
    // Memoization
    int solve(vector<int>& cost, int n, vector<int> &dp){
        if(n <= 1) return cost[n];
        if(dp[n] != -1) return dp[n];
        int oneStep = solve(cost, n-1, dp);
        int twoStep = solve(cost, n-2, dp);
        return dp[n] = cost[n] + min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(solve(cost, cost.size()-1, dp), solve(cost, cost.size()-2, dp));
    }
    */
    // Tabulation
    /*
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        for(int i = 2; i <= cost.size(); i++){
            int oneStep = dp[i-1] + cost[i-1];
            int twoStep = dp[i-2] + cost[i-2];
            dp[i] = min(oneStep, twoStep);
        }
        return dp[cost.size()];
    }
    */
    // Space optimization
    int minCostClimbingStairs(vector<int>& cost) {
        int prev_first = 0, prev_second = 0;
        for(int i = 2; i <= cost.size(); i++){
            int oneStep = prev_first + cost[i-1];
            int twoStep = prev_second + cost[i-2];
            prev_second = prev_first;
            prev_first = min(oneStep, twoStep);
        }
        return prev_first;
    }
};