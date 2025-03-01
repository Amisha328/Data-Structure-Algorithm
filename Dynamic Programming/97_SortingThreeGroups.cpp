// Sorting Three Groups
// Problem link:
// https://leetcode.com/problems/sorting-three-groups/

#include<bits/stdc++.h>
using namespace std;


// Recursion

class Solution {
public:
    int solve(vector<int>& nums, int idx, int prevGroup){
        if(idx == nums.size()) return 0;
        int currGroup = nums[idx];
        int res = INT_MAX;
        for(int newGroup = prevGroup; newGroup <= 3; newGroup++){
            int temp = solve(nums, idx+1, newGroup);
            if(currGroup != newGroup) temp++; // means we need to change the group hence adding the operation count. 
            res =  min(res, temp);
        }
        return res;
    }
    int minimumOperations(vector<int>& nums) {
        return solve(nums, 0, 1);
    }
};

// Memoization

class Solution {
public:
    int solve(vector<int>& nums, int idx, int prevGroup, vector<vector<int>> &dp){
        if(idx == nums.size()) return 0;
        if(dp[idx][prevGroup] != -1) return dp[idx][prevGroup];
        int currGroup = nums[idx];
        int res = INT_MAX;
        for(int newGroup = prevGroup; newGroup <= 3; newGroup++){
            int temp = solve(nums, idx+1, newGroup, dp);
            if(currGroup != newGroup) temp++; // means we need to change the group hence adding the operation count. 
            res =  min(res, temp);
        }
        return dp[idx][prevGroup] = res;
    }
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (4, -1));
        return solve(nums, 0, 1, dp);
    }
};

// Tabulation

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (4, 0));
        for(int idx = nums.size()-1; idx >= 0; idx--){
            for(int prevGroup = 3; prevGroup >= 1; prevGroup--){
                int currGroup = nums[idx];
                int res = INT_MAX;
                for(int newGroup = prevGroup; newGroup <= 3; newGroup++){
                    int temp = dp[idx+1][newGroup];
                    if(currGroup != newGroup) temp++; // means we need to change the group hence adding the operation count. 
                    res =  min(res, temp);
                }
                dp[idx][prevGroup] = res;
            }
        }
        return dp[0][1];
    }
};