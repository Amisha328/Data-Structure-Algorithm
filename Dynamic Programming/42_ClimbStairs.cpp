// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Problem link: https://leetcode.com/problems/climbing-stairs/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /*Memoization Solution: TC-> O(n) | SC -> O(n) + O(n)
    int dp[46];
    int solve(int n)
    {
        if(n <= 1) return dp[n] = 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
    */

    /* Tabulation Solution: TC -> O(n) | SC-> O(n)
     int climbStairs(int n) {
         int dp[n+1];
         dp[0] = 1; // We will remain on the same index when n = 0
         dp[1] = 1; // We can make jump from 0 to 1 only when n = 1
         
         for(int i = 2; i <= n; i++)
             dp[i] = dp[i-1] + dp[i-2];
         
         return dp[n];
     }
     */
    
    // Optimized Solution: TC->O(n) | SC->O(1)
    int climbStairs(int n) {
        int two_step = 1;
        int one_step = 1;
        
        for(int i = 2; i <= n; i++)
        {
            int cur = one_step + two_step;
            two_step = one_step;
            one_step = cur;
        }
        
        return one_step;
    }
};

int main()
{
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.climbStairs(n)<<endl;
    return 0;
}