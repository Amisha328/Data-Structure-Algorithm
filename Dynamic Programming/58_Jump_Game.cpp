// Jump Game VI
// Problem link:
// https://leetcode.com/problems/jump-game-vi/

#include<bits/stdc++.h>

class Solution {
public:
    // Memoization - Gives TLE
    // TC: O(nk) | SC: O(n)+O(n)
    /*
    int solve(vector<int>& nums, int n, int k, vector<int> &dp){
        if(n == 0) return nums[0];
        if(dp[n] != -1e9) return dp[n];
        int mscore = -1e9;
        for(int i = 1; i <= k; i++){
            if(n-i >= 0)
                 mscore = max(mscore, solve(nums, n-i, k, dp) + nums[n]);
        }
        return dp[n] = mscore;
    }
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), -1e9);
        return solve(nums, nums.size()-1, k, dp);
    }
    */
    /*
    // Tabulation - Gives TLE
    // TC: O(nk) | SC: O(n)+O(n)
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= k; j++){
                if(i-j >= 0)
                  dp[i] = max(dp[i], dp[i-j] + nums[i]);  
            }
        }
        return dp[nums.size()-1];
    }
    */
   
    // DP + MaxHeap
    // TC: O(nlogk) | SC: O(n)
    int maxResult(vector<int>& nums, int k) {
        // Stores the max cost path from ith to jth index
        vector<int> dp(nums.size(), 0);
        
        priority_queue<pair<int, int>> max_heap; // {dp[idx], idx}
        for(int i = nums.size()-1; i >= 0; i--){
            // pop out elements that are out of window of size k to find the max element in that range.
            while(max_heap.size() && max_heap.top().second > i+k)
                max_heap.pop();
            // adding the current max cost and current index cost in dp 
            if(!max_heap.empty()) dp[i] = max_heap.top().first + nums[i];
            else dp[i] = 0 + nums[i];
            max_heap.push({dp[i], i});
        }
        return dp[0];
    }
   
};