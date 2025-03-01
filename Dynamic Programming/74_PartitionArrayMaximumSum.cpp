// Partition Array for Maximum Sum
// Problem link:
// https://leetcode.com/problems/partition-array-for-maximum-sum/
// https://practice.geeksforgeeks.org/problems/partition-array-for-maximum-sum/1?
// https://www.codingninjas.com/codestudio/problem-details/maximum-subarray_3755255

#include<bits/stdc++.h>
using namespace std;

// Memoization:
// TC -> O(N X K) | SC -> O(N) + O(N)

class Solution {
private:
    int f(int i, int n, vector<int>& arr, int k, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int len = 0, temp = INT_MIN, sum = 0, maxSum = 0;
        for(int j = i; j < min(n, i+k); j++){
            len++;
            temp = max(temp, arr[j]);
            sum = (len * temp) + f(j+1, n, arr, k, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, n, arr, k, dp);
    }
};

// Tabulation
// TC -> O(N X K) | SC -> O(N)

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            int len = 0, temp = INT_MIN, sum = 0, maxSum = 0;
            for(int j = i; j < min(n, i+k); j++){
                len++;
                temp = max(temp, arr[j]);
                sum = (len * temp) + f(j+1, n, arr, k, dp);
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};