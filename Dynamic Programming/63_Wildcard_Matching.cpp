// Wildcard Matching
// Problem link:
// https://leetcode.com/problems/wildcard-matching/description/
// https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1?
// https://www.codingninjas.com/codestudio/problem-details/wildcard-pattern-matching_701650

#include <bits/stdc++.h>
using namespace std;

// Memoization :- 0-based indexing code
// TC-> O(N X M)
// SC -> O(N X M) + O(N + M)
class Solution{
    private:
        int f(int i, int j, string &pattern, string &str, vector<vector<int>> &dp){
            if(i < 0 && j < 0) return true;
            else if(i < 0 && j >= 0) return false;
            else if(j < 0 && i >= 0){
                for(int ii = 0; ii <= i; ii++){
                    if(pattern[ii] != '*')
                        return false;
                }
                return true;
            }
            if(dp[i][j] != -1) return dp[i][j];
            
            if(pattern[i] == str[j] || pattern[i] == '?')
                return dp[i][j] = f(i-1, j-1, pattern, str, dp);
            else if(pattern[i] == '*')
                return dp[i][j] = f(i-1, j, pattern, str, dp) || f(i, j-1, pattern, str, dp);
            return false;
        } 
        public:
        int wildCard(string pattern,string str)
        {
            int n = pattern.size();
            int m = str.size();
            vector<vector<int>> dp(n, vector<int>(m, -1));
            return f(n-1, m-1, pattern, str, dp);
        }
};
// Memoization :- 1-based indexing code
// TC-> O(N X M)
// SC -> O(N X M) + O(N + M)
class Solution{
    private:
        int f(int i, int j, string &pattern, string &str, vector<vector<int>> &dp){
            if(i == 0 && j == 0) return true;
            else if(i == 0 && j > 0) return false;
            else if(j == 0 && i > 0){
                for(int ii = 1; ii <= i; ii++){
                    if(pattern[ii-1] != '*')
                        return false;
                }
                return true;
            }
            if(dp[i][j] != -1) return dp[i][j];
            
            if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                return dp[i][j] = f(i-1, j-1, pattern, str, dp);
            else if(pattern[i-1] == '*')
                return dp[i][j] = f(i-1, j, pattern, str, dp) || f(i, j-1, pattern, str, dp);
            return false;
        } 
    public:
        int wildCard(string pattern,string str)
        {
            int n = pattern.size();
            int m = str.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
            return f(n, m, pattern, str, dp);
        }
};

// Tabulation:
// TC-> O(N X M)
// SC -> O(N X M)

class Solution{
public:
        int wildCard(string pattern,string str)
        {
            int n = pattern.size();
            int m = str.size();
            
            vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
            dp[0][0] = true;
            for(int j = 1; j <= m; j++) dp[0][j] = false;
            for(int i = 1; i <= n; i++){
                bool flag = true;
                for(int ii = 1; ii <= i ; ii++){
                    if(pattern[ii-1] != '*') {
                        flag = false;
                        break;
                    }
                }
                dp[i][0] = flag;
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                        dp[i][j] = dp[i-1][j-1];
                    else if(pattern[i-1] == '*')
                        dp[i][j] = dp[i-1][j] | dp[i][j-1];
                    else dp[i][j] = false;
                }
            }
            return dp[n][m];
        }
};

// Space Optimization:
// TC - > O(N X M)
// SC -> 2 X O(M)
class Solution{
public:
int wildCard(string pattern,string str)
        {
            int n = pattern.size();
            int m = str.size();
            
            vector<bool> prev(m+1, false), curr(m+1, false);
            prev[0] = true;
            for(int j = 1; j <= m; j++) prev[j] = false;
            
            for(int i = 1; i <= n; i++){
               /*
               curr is the current row's column and that curr's 
               0th row has to be assigned everytime.
               */
                bool flag = true;
                for(int ii = 1; ii <= i ; ii++){
                    if(pattern[ii-1] != '*') {
                        flag = false;
                        break;
                    }
                }
                /*
                for every row you are assigning the 0th col's value
                */
                curr[0] = flag;
                for(int j = 1; j <= m; j++){
                    if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                        curr[j] = prev[j-1];
                    else if(pattern[i-1] == '*')
                        curr[j] = prev[j] | curr[j-1];
                    else curr[j] = false;
                }
                prev = curr;
            }
            return prev[m];
        }
};