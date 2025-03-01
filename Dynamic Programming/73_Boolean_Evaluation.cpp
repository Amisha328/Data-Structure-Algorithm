// Evaluate Boolean Expression to True
// Problem link:
// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.codingninjas.com/codestudio/problem-details/problem-name-boolean-evaluation_1214650

#include <bits/stdc++.h> 
using namespace std;

// Memoization
// TC -> O(N X N X N) | SC -> O(N X N X 2) + stack space

int mod = 1e9+7;
int f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp){
        if(i > j) return 0;
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        if(i == j){
            if(isTrue == 1) return exp[i] == 'T';
            else return exp[i] == 'F';
        }
        long long ways = 0;
        for(int idx = i+1; idx <= j-1; idx += 2){
            long long lT = f(i, idx-1, 1, exp, dp);
            long long rT = f(idx+1, j, 1, exp, dp);
            long long lF = f(i, idx-1, 0, exp, dp);
            long long rF = f(idx+1, j, 0, exp, dp);
            
            if(exp[idx] == '&'){
                if(isTrue) ways += (lT * rT) % mod;
                else ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
            }
            else if(exp[idx] == '|'){
                if(isTrue) ways = (ways + (lT * rF) % mod +(lF * rT) % mod + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rF) % mod) % mod;
            }
            else if(exp[idx] == '^'){
                if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT)% mod )% mod;
                else ways = (ways + (lT * rT)% mod + (lF * rF)% mod)% mod;
            }
        }
        return dp[i][j][isTrue] = ways % mod;
}
int evaluateExp(string & exp) {
    int N = exp.size();
    vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(N+1, vector<long long>(2, -1)));
    return f(0,N-1, 1, exp, dp);
}

// Tabulation:

int countWays(int N, string exp){
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(2, 0)));
        // return f(0,N-1, 1, S, dp);
        for (int i = 0; i < N; i++)
        {
            dp[i][i][1] = exp[i] == 'T';
            dp[i][i][0] = exp[i] == 'F';
        }
        for(int i = N-1; i >= 0; i--){
            for(int j = i+1; j < N; j++){
                for(int isTrue = 0; isTrue <= 1; isTrue++){
                    int ways = 0;
                    for(int idx = i+1; idx <= j-1; idx += 2){
                        int lT = dp[i][idx-1][1];
                        int rT = dp[idx+1][j][1];
                        int lF = dp[i][idx-1][0];
                        int rF = dp[idx+1][j][0];
                        
                        if(exp[idx] == '&'){
                            if(isTrue) ways += (lT * rT) % mod;
                            else ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
                        }
                        else if(exp[idx] == '|'){
                            if(isTrue) ways = (ways + (lT * rF) % mod +(lF * rT) % mod + (lT * rT) % mod) % mod;
                            else ways = (ways + (lF * rF) % mod) % mod;
                        }
                        else if(exp[idx] == '^'){
                            if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT)% mod )% mod;
                            else ways = (ways + (lT * rT)% mod + (lF * rF)% mod)% mod;
                        }
                    }
                    dp[i][j][isTrue] = ways % mod;
                }
            }
        }
        return dp[0][N-1][1];       
}
