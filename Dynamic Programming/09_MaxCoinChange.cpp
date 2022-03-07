// Problem Statement: https://practice.geeksforgeeks.org/problems/coin-change-number-of-ways/1/
// https://www.codingninjas.com/codestudio/problem-details/ways-to-make-coin-change_630471

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Memoization: TC-> O(N * tar) | SC-> O(N * tar) + O(N)
    /*
    long solve(int num[], int idx, int value, vector<vector<long>> &dp)
    {
        if(idx == 0)
            return (value%num[idx] == 0);
        if(dp[idx][value] != -1) return dp[idx][value];
        long not_take = solve(num, idx-1, value, dp);
        long take = 0;
        if(num[idx] <= value) 
            take = solve(num, idx, value-num[idx], dp);
        
        return dp[idx][value] = (take + not_take);
    }
    long countWaysToMakeChange(int num[], int n, int value)
    {
       vector<vector<long>> dp(n, vector<long>(value+1, -1));
       return solve(num, n-1, value, dp);
    }
    */

    /*
    // Tabulation: TC-> O(N * tar) | SC-> O(N * tar)
    long countWaysToMakeChange(int num[], int n, int value)
    {
        vector<vector<long>> dp(n, vector<long>(value+1, 0));
        for(int T = 0; T <= value; T++)
            dp[0][T] = (T%num[0] == 0);
        for(int idx = 1; idx < n; idx++)
        {
            for(int T = 0; T <= value; T++)
            {
                long not_take = dp[idx-1][T];
                long take = 0;
                if(num[idx] <= T) 
                    take = dp[idx][T-num[idx]];

                dp[idx][T] = (take + not_take);
            }
        }
        
        return dp[n-1][value];
    }
    */

    // Space Optimization: TC-> O(N * tar) | SC-> O(tar)
    long countWaysToMakeChange(int num[], int n, int value)
    {
        vector<long> prev(value+1, 0);
        vector<long> curr(value+1, 0);
        
        for(int T = 0; T <= value; T++)
            prev[T] = (T%num[0] == 0);
        for(int idx = 1; idx < n; idx++)
        {
            for(int T = 0; T <= value; T++)
            {
                long not_take = prev[T];
                long take = 0;
                if(num[idx] <= T) 
                    take = curr[T-num[idx]];

                curr[T] = (take + not_take);
            }
            prev = curr;
        }
        
        return prev[value];
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
	    cout<<obj.countWaysToMakeChange(coins,numberOfCoins,value)<<endl;
	    
	return 0;
}
