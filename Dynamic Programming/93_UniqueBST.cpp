// Unique Binary Search Trees
// Problem link:
// https://leetcode.com/problems/unique-binary-search-trees/description/
// https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1?

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution

class Solution
{
    private:
    int solve(int n){
        if(n <= 1) return 1;
        int ans = 0;
        // making each node as root node
        for(int i = 1; i <= n; i++){
            ans += solve(i-1) * solve(n-i);
        }
        return ans;
    }
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        return solve(N);
    }
};

// Memoization:

class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        // making each node as root node
        for(int i = 1; i <= n; i++){
            ans += solve(i-1, dp) * solve(n-i, dp);
        }
        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// Tabulation:

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        // return solve(n, dp);
        dp[0] = 1;
        dp[1] = 1;
        for(int j = 2; j <= n; j++){
            int ans = 0;
            // making each node as root node
            for(int i = 1; i <= n; i++){
                if(j-i >= 0)ans += dp[i-1] * dp[j-i];
            }
            dp[j] = ans;
        }
        return dp[n];
    }
};