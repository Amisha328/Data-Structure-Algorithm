// Combination Sum IV
// Problem link:
// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252?leftPanelTab=1
// https://leetcode.com/problems/combination-sum-iv/description/

#include<bits/stdc++.h>
using namespace std;

// Memoization
// TC -> O(tar) | SC-> O(tar) + O(tar)
class Solution {
private:
    int f(vector<int>& nums, int target, vector<int> &dp){
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= target)
                sum += f(nums, target-nums[i], dp);
        }
        return dp[target] = sum;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return f(nums, target, dp);
    }
};

// Tabulation
// TC -> O(tar) | SC-> O(tar)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] <= i) {
                    dp[i] +=  (long long int) dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};