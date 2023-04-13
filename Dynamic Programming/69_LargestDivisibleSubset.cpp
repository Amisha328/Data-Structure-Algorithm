// Largest Divisible Subset
// Problem links:
// https://leetcode.com/problems/largest-divisible-subset/description/
// https://practice.geeksforgeeks.org/problems/e866d887f78664cdbf24c61ef9404691f4fb9e59/1
// https://www.codingninjas.com/codestudio/problem-details/divisible-set_3754960

#include <bits/stdc++.h> 
using namespace std;

// TC -> O(N X N) + O(N) | SC -> O(N) X 3
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), hash(n);
    int maxi = 1, lastIndex = 0;
    for(int i = 0; i < n; i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(arr[i]%arr[prev] == 0 && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
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