//  Distinct Subsequences
// Problem links: 
// https://leetcode.com/problems/distinct-subsequences/description/
// https://practice.geeksforgeeks.org/problems/distinct-occurrences/1?
// https://www.codingninjas.com/codestudio/problem-details/subsequence-counting_3755256

// Memoization:
// TC -> O(N X M)
// SC -> O(N X M) + O(N + M)

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int i, int j, string &s,string &t, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = solve(i-1, j-1, s , t, dp) + solve(i-1, j, s, t, dp);
        return dp[i][j] = solve(i-1, j, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};


// Tabulation
// TC -> O(N X M)
// SC -> O(N X M)

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};

// Space optimization from 2D to 1D arrays
// TC -> O(N X M)
// SC -> 2 X O(M)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // if getting TLE with int try long long
        // if still geting TLE change to double then typecast to int at the end.
        vector<double> prev(m+1, 0), curr(m+1, 0);
        prev[0] = curr[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};

// Space optimization from two 1D arrays to single 1D array
// TC -> O(N X M)
// SC -> O(M)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // if getting TLE with int try long long
        // if still geting TLE change to double then typecast to int at the end.
        vector<double> dp(m+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = m; j >= 1; j--){
                if(s[i-1] == t[j-1])
                    dp[j] = dp[j-1] + dp[j];
            }
        }
        return (int)dp[m];
    }
};