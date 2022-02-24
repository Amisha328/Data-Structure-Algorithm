// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements
// in both parts is the same.
// Problem link: https://www.codingninjas.com/codestudio/problem-details/partition-equal-subset-sum_892980
// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
/*
    // Memoization:
    bool solve(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
                        
        if(dp[idx][target] != -1) return dp[idx][target];
                        
        bool not_take = solve(idx-1, target, arr, dp);
        bool take = false;
        if(target >= arr[idx])
        take = solve(idx-1, target-arr[idx], arr, dp);
                        
        return dp[idx][target] = (not_take | take);
    }
    bool canPartition(vector<int> &arr, int n)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 != 0)
            return 0;
        else
        {
            int k = sum/2;
            vector<vector<int>> dp(n, vector<int>(k+1, -1));
            return solve(n-1, k, arr, dp);
        }
    }
    */

    /*
    // Tabulation:
    bool canPartition(vector<int> &arr, int n)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 != 0)
            return 0;

        int k = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));
                    
        for(int idx = 0; idx < n; idx++)  dp[idx][0] = true;
        dp[0][arr[0]] = true;
                    
        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 1; target <= k; target++)
            {
                bool not_take = dp[idx-1][target];
                bool take = false;
                if(target >= arr[idx])
                        take = dp[idx-1][target-arr[idx]];
                dp[idx][target] = (not_take | take);
            }
        }
          
        return dp[n-1][k];
    }
    */

   // Space Optimized solution: TC -> O(n*target) | SC -> O(target)
    bool canPartition(vector<int> &arr, int n)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 != 0)
            return 0;

        int k = sum/2;
        vector<bool> prev(k+1, 0), curr(k+1, 0);
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 1; target <= k; target++)
            {
                bool not_take = prev[target];
                bool take = false;
                if(target >= arr[idx])
                    take = prev[target-arr[idx]];
                curr[target] = (not_take | take);
            }        
            prev = curr;
        }            
        return prev[k];
    }
};

int main()
{
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.canPartition(arr, N))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    return 0;
}