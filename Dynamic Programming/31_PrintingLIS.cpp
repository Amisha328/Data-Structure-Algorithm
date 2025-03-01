// Printing Longest Increasing Subsequence
// Problem link:
// https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

#include <bits/stdc++.h>
using namespace std;

// TC -> O(N X N) | SC -> O(N)
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1), hash(n, 0);
        int maxi = 1;
        int lastIndex = 0;
        for(int i = 0; i < n; i++){
             hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
                if(dp[i] > maxi){
                    maxi = dp[i];
                    lastIndex = i;
                }
            }
        }
        vector<int> lis;
        lis.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            lis.push_back(arr[lastIndex]);
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};