// Problem Statement: https://practice.geeksforgeeks.org/problems/coin-change-number-of-ways/1/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    long long numberOfWays(int coins[],int n,int value)
    {
        
        int dp[n+1][value+1];
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= value; j++)
            {
                if(i == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
        }
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j <= value; j++)
            {
                if(coins[i-1] <= j)
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][value];
    }
};


int main() {
    
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //inserting coins to the array
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function numberOfWays
	    cout<<obj.numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	return 0;
}  // } Driver Code Ends