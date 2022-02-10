// Egg Dropping Problem
// Problem Statement: https://www.includehelp.com/algorithms/egg-dropping-problem-using-dynamic-programming.aspx
// Problem link:
// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// https://leetcode.com/problems/super-egg-drop/

// Conditions:
// Egg may break from 1st floor
// Egg may not break from the top floor
// If an egg breaks from a floor, it will break from all the higher floors.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor
    int dp[101][10001];
    int solve(int e, int f)
    {
        // only one floor, so only one attempt is required
        if(f == 0 || f == 1) return f;
        //if only one egg is given then in the worst case, then we will have to check for 
        //all the floors starting from first floor
        if(e == 1) return f;
        
        if(dp[e][f] != -1)
            return dp[e][f];
        
        int ans = INT_MAX;
        int l = 1, h = f;
        int k;
        while(l <= h)
        {
            int k = (h+l)/2;
            int low, high;
            
            // egg will break - check lower floors
            if(dp[e-1][k-1] != -1)
                low = dp[e-1][k-1];
            else
            {
                low = solve(e-1, k-1);
                dp[e-1][k-1] = low;
            }
            
            // egg will not break - check higher floors
            if(dp[e][f-k] != -1)
                high = dp[e][f-k];
            else
            {
                high = solve(e, f-k);
                dp[e][f-k] = high;
            }
            
            int temp = 1 + max(low, high);
            ans = min(ans, temp);
            
            // if attempts to break egg is less than attemps to not break egg at current floor
            if(low < high)
                l = k+1; // move higher up floor
            else
                h = k-1; // else move down
        }
        
        return dp[e][f] = ans;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};

int main()
{
        int n, k;
        cin>>n>>k;
        Solution ob;
       
        cout<<ob.eggDrop(n, k)<<endl;
    return 0;
}
  