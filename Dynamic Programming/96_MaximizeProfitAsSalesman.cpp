// Maximize the Profit as the Salesman
// Problem link:
// https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/

#include<bits/stdc++.h>
using namespace std;

// Recursive solution:

class Solution {
public:
    vector<int> temp;
    int solve(vector<vector<int>>& offers, int idx){
        if(idx == offers.size()) return 0;
        int notTake = solve(offers, idx+1);
        int next_idx = upper_bound(temp.begin(), temp.end(), offers[idx][1]) - temp.begin();
        // OR
        // int next_idx = lower_bound(temp.begin(), temp.end(), offers[idx][1]+1) - temp.begin();
        int take = offers[idx][2] + solve(offers, next_idx);
        return max(take, notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        // storing start of all the offers in a seperate array
        for(auto x: offers){
            temp.push_back(x[0]);
        }
        return solve(offers, 0);
    }
};

// Memoization:

class Solution {
public:
    vector<int> temp;
    int solve(vector<vector<int>>& offers, int idx, vector<int> &dp){
        if(idx == offers.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int notTake = solve(offers, idx+1, dp);
        int next_idx = upper_bound(temp.begin(), temp.end(), offers[idx][1]) - temp.begin();
        // OR
        // int next_idx = lower_bound(temp.begin(), temp.end(), offers[idx][1]+1) - temp.begin();
        int take = offers[idx][2] + solve(offers, next_idx, dp);
        return dp[idx] = max(take, notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        // storing start of all the offers in a seperate array
        for(auto x: offers){
            temp.push_back(x[0]);
        }
        vector<int> dp(offers.size(), -1);
        return solve(offers, 0, dp);
    }
};

// Tabulation:

class Solution {
public:
    vector<int> temp;
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        // storing start of all the offers in a seperate array
        for(auto x: offers){
            temp.push_back(x[0]);
        }
        vector<int> dp(offers.size()+1, 0);
        
        for(int idx = offers.size()-1; idx >= 0; idx--){
            int notTake = dp[idx+1];
            int next_idx = upper_bound(temp.begin(), temp.end(), offers[idx][1]) - temp.begin();
            // OR int next_idx = lower_bound(temp.begin(), temp.end(), offers[idx][1]+1) - temp.begin();
            int take = offers[idx][2] + dp[next_idx];
            dp[idx] = max(take, notTake);
        }
        return dp[0];
    }
};