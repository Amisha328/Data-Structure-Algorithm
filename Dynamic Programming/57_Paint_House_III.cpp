// Paint House III
// Problem link:
// https://leetcode.com/problems/paint-house-iii/

#include<bits/stdc++.h>
class Solution {
public:
    // Memoization Solution
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int curr_idx, int neighbour, int prev_color, vector<vector<vector<int>>> &dp){
        
        if(curr_idx == m){
            return neighbour == target? 0 : 1e6+1;
        }
        if(neighbour > target)
            return 1e6+1;
        
        if(dp[curr_idx][neighbour][prev_color] != -1)
            return dp[curr_idx][neighbour][prev_color];
        // if current house is not painted
        if(houses[curr_idx] == 0){
            int minCost = 1e6+1;
            // coloring the house with each possible color
            for(int c = 1; c <= n; c++){
                int new_neighbour = neighbour;
                if(c != prev_color){
                    new_neighbour = neighbour + 1;
                }
                minCost = min(minCost, cost[curr_idx][c-1] + solve(houses, cost, m, n, target, curr_idx+1, new_neighbour, c, dp));
            }
            return dp[curr_idx][neighbour][prev_color] = minCost;
        }
        // if house is already painted
        else {
            int new_neighbour = neighbour;
            if(houses[curr_idx] != prev_color)
                new_neighbour = neighbour + 1;
            return  dp[curr_idx][neighbour][prev_color] = solve(houses, cost, m, n, target, curr_idx+1, new_neighbour, houses[curr_idx], dp);
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector< vector<int>>> dp(m , vector<vector<int>> (target+1, vector<int> (n+1, -1)));
        int ans = solve(houses, cost, m, n, target, 0, 0, 0, dp);
        return ans < 1e6+1? ans : -1;
    }
};