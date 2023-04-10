// Longest Increasing Subsequence
// Problem Statement: 
// https://leetcode.com/problems/longest-increasing-subsequence/
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1?
// https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?leftPanelTab=0


#include <bits/stdc++.h>
using namespace std;

// Simple recursive code
// TC -> O(2 ^ N) | SC -> O(N)
class Solution {
    private:
        int f(int idx, int prev_idx, vector<int>& nums, int n){
            if(idx == n) return 0;
            int len = 0 + f(idx+1, prev_idx, nums, n);
            if(prev_idx == -1 || nums[idx] > nums[prev_idx])
                len = max(len, 1 + f(idx+1, idx, nums, n));
            return len;
        }
    public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return f(0, -1, nums, n);
    }
};

// Memoization:
// TC -> O(N X N) | SC -> O(N X N) + O(N)

class Solution {
private:
    int f(int idx, int prev_idx, vector<int>& nums, vector<vector<int>> &dp){
        if(idx == nums.size()) return 0;
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1]; // prev_idx+1 due to co-ordinate change
        int len = 0;
        len = 0 + f(idx+1, prev_idx, nums, dp);
        if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            len = max(len, 1 + f(idx+1, idx, nums, dp));
        return dp[idx][prev_idx+1] = len; // prev_idx+1 due to co-ordinate change
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // we are using dp of n X (n+1) as 
        // idx ranges from 0 to n-1 and prev_idx ranges from -1 to (n-1) so we are doing co-cordinate shifting from 0 based indexing to 1 based indexing for prev_idx
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};

// Tabulation:
// TC -> O(N X N) | SC -> O(N X N)


class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx = n-1; idx >= 0; idx--){
            // weare not taking prev idx from n-1 to -1 beacause according to our logic we just want the prev index element
            for(int prev = idx-1; prev >= -1; prev--){
                int len = 0;
                // making co-ordinate change at all the place for prev index
                len = 0 + dp[idx+1][prev+1];
                if(prev == -1 || nums[idx] > nums[prev])
                    len = max(len, 1 + dp[idx+1][idx+1]);
                dp[idx][prev+1] = len; // prev_idx+1 due to co-ordinate change
            }
        }
        return dp[0][-1+1];
    }
};

// Space Optimization:
// TC -> O(N X N) | SC -> O(N X 2)

class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ahead(n+1, 0), curr(n+1, 0);
        for(int idx = n-1; idx >= 0; idx--){
            for(int prev = idx-1; prev >= -1; prev--){
                int len = 0;
                len = 0 + ahead[prev+1];
                if(prev == -1 || nums[idx] > nums[prev])
                    len = max(len, 1 + ahead[idx+1]);
               curr[prev+1] = len; 
            }
            ahead = curr;
        }
        return ahead[-1+1];
    }
};

// Further Optimization
// TC -> O(N X N) | SC -> O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[prev]);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};


// Binary Serach Code:
// TC-> O(NlogN) | SC -> O(N)
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int idx = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            temp[idx] = arr[i];
        }
    }
    return len;
}
