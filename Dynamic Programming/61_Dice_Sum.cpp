// Number of Dice Rolls With Target Sum
// Problem link:
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// https://practice.geeksforgeeks.org/problems/dice-throw5349/1
// https://www.codingninjas.com/codestudio/problem-details/dice-throws_799924

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if(target < n || (target/k) >= n && (target%k) != 0) return 0;
        int MOD = 1000000007;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for(int d = 1; d <= n; d++)
        {
            for(int t = 1; t <= target; t++)
            {
                for(int f = 1; f <= k && f <= t; f++)
                {
                    /*
                    To get a sum target from i dices, there are f possible scenarios for the last dice : 
                    it can take any value from 1 to f and therefore it for each value "k" of this 
                    last dice you need the other i-1 dices to have a sum of "target-k" to get to the total sum of "target" 
                    */
                    dp[d][t] = (dp[d][t]%MOD + dp[d-1][t-f]%MOD)%MOD;
                }
            }
        }
        //   for(int i = 0; i <= n; i++)
        //    {
        //         for(int j = 0; j <= target; j++)
        //             cout<<dp[i][j]<<" ";
        //         cout<<endl;
        //     }
        return dp[n][target];
    }
};