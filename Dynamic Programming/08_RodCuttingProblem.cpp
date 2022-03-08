// Problem statement: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#
// https://www.codingninjas.com/codestudio/problem-details/rod-cutting-problem_800284

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  /*
    // Memoization:
    int solve(vector<int> &price, int idx, int N, vector<vector<int>> &dp)
    {
        if(idx == 0)
            return N*price[0];
        if(dp[idx][N] != -1) return dp[idx][N];
        
        int notTake = 0 + solve(price, idx-1, N, dp);
        int take = INT_MIN;
        int rodLen = idx+1;
        if(rodLen <= N) 
            take = price[idx] + solve(price, idx, N-rodLen, dp);
        
        return dp[idx][N] = max(take, notTake);
        
    }
    int cutRod(vector<int> &price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(price, n-1, n, dp);   
    }
*/
    /*
    // Tabulation:
    int cutRod(vector<int> &price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int N = 0; N <= n; N++)
            dp[0][N] = N * price[0];
        for(int idx = 1; idx < n; idx++)
        {
            for(int N = 0; N <= n; N++)
            {
                int notTake = 0 + dp[idx-1][N];
                int take = INT_MIN;
                int rodLen = idx+1;
                if(rodLen <= N) 
                    take = price[idx] + dp[idx][N-rodLen];

                dp[idx][N] = max(take, notTake);
            }
        }
        return dp[n-1][n];
    }*/

    /*
    // Space Optimization:
    int cutRod(vector<int> &price, int n)
    {
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        
        for(int N = 0; N <= n; N++)
            prev[N] = N * price[0];
        for(int idx = 1; idx < n; idx++)
        {
            for(int N = 0; N <= n; N++)
            {
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodLen = idx+1;
                if(rodLen <= N) 
                    take = price[idx] + curr[N-rodLen];

                curr[N] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[n];
    }
    */
    
    //  More optimized Solution:
    int cutRod(vector<int> &price, int n)
    {
        vector<int> prev(n+1, 0);
        for(int N = 0; N <= n; N++)
            prev[N] = N * price[0];
        for(int idx = 1; idx < n; idx++)
        {
            for(int N = 0; N <= n; N++)
            {
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodLen = idx+1;
                if(rodLen <= N) 
                    take = price[idx] + prev[N-rodLen];

                prev[N] = max(take, notTake);
            }
        }
        return prev[n];
    }

    /*
    // Aditya Verma's Solution
    int cutRod(int price[], int n) {
        //code here
        int len[n+1];
        for(int i = 0; i < n; i++)
            len[i] = i+1;
        
        int dp[n+1][n+1];
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(len[i-1] <= j)
                    dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][n];
    }
    */
};


int main() 
{
        int n;
        cin >> n;
       vector<int> price(n);
        for (int i = 0; i < n; i++) 
            cin >> price[i];
            
        Solution ob;

        cout << ob.cutRod(price, n) << endl;
    return 0;
}  
