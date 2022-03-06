// Problem Statement: https://leetcode.com/problems/coin-change/
// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

 
class Solution{
public:
    /*
    // Aditya Verma Solution
	int minCoins(int coins[], int n, int value) 
	{ 
	          int dp[n+1][value+1];
                    for(int i = 0; i <= n; i++)
                    {
                              for(int j = 0; j <= value; j++)
                              {
                              if(j == 0)
                                        dp[i][j] = 0;
                              if(i == 0)
                                        dp[i][j] = INT_MAX-1;
                              }
                    }
                    
                    for(int i = 1; i <= value; i++)
                    {
                              if(i%coins[0] == 0)
                              dp[1][i] = (i/coins[0]);
                              else
                              dp[1][i] = INT_MAX-1;
                    }
                    
                    for(int i = 2; i <= n; i++)
                    {
                              for(int j = 1; j <= value; j++)
                              {
                              if(coins[i-1] <= j)
                                        dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                              else
                                        dp[i][j] = dp[i-1][j];
                              }
                    }
                    if(dp[n][value] == INT_MAX-1)
                              return -1;
                    
                    return dp[n][value];

        */

       /*
        // gfg solution:
            int dp[value+1];
            // dp[i] -> minimum number of coins required to get value 
            dp[0] = 0;
            for(int i = 1; i <= value; i++)
                dp[i] = INT_MAX;
            
            for(int i = 1; i <= value; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(coins[j] <= i) // find the values in array <= index number
                    {
                        int res = dp[i-coins[j]];  
                        if(res != INT_MAX)
                        dp[i] = min(dp[i], res+1);
                    }
                }
            }
        
        if(dp[value] == INT_MAX)
            return -1;
        
        return dp[value];
	} 
    */


   // Striver Solutions:
    /*
   // Memoization: TC->O(N*tar) | SC->O(N*tar)+O(N)
    int solve(vector<int> &num, int T, int idx, vector<vector<int>> &dp)
    {
        if(idx == 0)
        {
            if(T%num[0] == 0) return T/num[0];
            else return 1e9;
        }
        if(dp[idx][T] != -1) return dp[idx][T];
        int not_take = 0 + solve(num, T, idx-1, dp);
        int take = 1e9;
        if(num[idx] <= T)
            take = 1 + solve(num, T-num[idx], idx, dp);
        
        return dp[idx][T] = min(take, not_take);
    }
    int minCoins(vector<int> &num, int x)
    {
        // Write your code here.
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(x+1, -1));
        int ans = solve(num, x, n-1, dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
    */

    /*
    // Tabulation: TC->O(N*tar) | SC->O(N*tar)
    int minCoins(vector<int> &num, int x)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(x+1, 0));
        for(int T = 0; T <= x; T++)
        {
            if(T%num[0] == 0)
                dp[0][T] = T/num[0];
            else
                dp[0][T] = 1e9;
        }
        for(int idx = 1; idx < n; idx++)
        {
            for(int T = 0; T <= x; T++)
            {
                int not_take = 0 + dp[idx-1][T];
                int take = 1e9;
                if(num[idx] <= T)
                    take = 1 +  dp[idx][T-num[idx]];

                dp[idx][T] = min(take, not_take);
            }
        }
        int ans = dp[n-1][x];
        if(ans >= 1e9) return -1;
        else return ans;
    }
    */

   // Space Optimization: TC->O(N*tar) | SC->O(N*tar)
    int minCoins(vector<int> &num, int x)
    {
        // Write your code here.
        int n = num.size();
        
        vector<int> prev(x+1, 0);
        vector<int> curr(x+1, 0);
        
        for(int T = 0; T <= x; T++)
        {
            if(T%num[0] == 0)
                prev[T] = T/num[0];
            else
                prev[T] = 1e9;
        }
        for(int idx = 1; idx < n; idx++)
        {
            for(int T = 0; T <= x; T++)
            {
                int not_take = 0 + prev[T];
                int take = 1e9;
                if(num[idx] <= T)
                    take = 1 +  curr[T-num[idx]];

            curr[T] = min(take, not_take);
            }
            prev = curr;
        }
        int ans = prev[x];
        if(ans >= 1e9) return -1;
        else return ans;
    }
	  
};


int main() 
{
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, v) << "\n";
	     
    return 0;
}
  
