// Problem Statement: https://leetcode.com/problems/coin-change/


#include <bits/stdc++.h>
using namespace std;

 
class Solution{

	public:
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
	} 
	  
};


int main() 
{
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    return 0;
}
  