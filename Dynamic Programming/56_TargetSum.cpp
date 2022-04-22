// Target Sum Problem - Same as count the subset with given difference (06).
// Problem link: https://www.codingninjas.com/codestudio/problem-details/target-sum_4127362
// https://leetcode.com/problems/target-sum/

#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
/*
    // Memoization:
    int solve(vector<int> &num, int idx, int sum, vector<vector<int>> &dp)
    {
            if(idx == 0)
            {
                if(sum == 0 && num[0] == 0) return 2;
                if(sum == 0 || sum == num[0]) return 1;
                return 0;
            }
            if(dp[idx][sum] != -1) return dp[idx][sum];
            
            int not_pick = solve(num, idx-1, sum, dp);
            int pick = 0;
            if(num[idx] <= sum) pick = solve(num, idx-1, sum-num[idx], dp);
            
            return dp[idx][sum] = (pick + not_pick);
    }
    int countPartitions(int n, int target, vector<int> &arr) {
        int tot_sum = 0;
        for(auto i = 0; i < n; i++)
            tot_sum += arr[i];
        
        if((tot_sum-target) < 0 || (tot_sum-target)%2) return 0;
        
        int tar = (tot_sum-target)/2;
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        return solve(arr, n-1, tar, dp);
    }
    */


    /*
    // Tabulation:
    int countPartitions(int n, int target, vector<int> &arr) 
    {
        int tot_sum = 0;
        for(auto i = 0; i < n; i++)
            tot_sum += arr[i];
        
        if((tot_sum-target) < 0 || (tot_sum-target)%2) return 0;
        
        int tar = (tot_sum-target)/2;
        vector<vector<int>> dp(n, vector<int>(tar+1, 0));
        
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        if(arr[0] != 0 && arr[0] <= tar) dp[0][arr[0]] = 1;
                        
        for(int idx = 1; idx < n; idx++)
        {
            for(int sum = 0; sum <= tar; sum++)
            {
                    int not_pick = dp[idx-1][sum];
                    int pick = 0;
                    if(arr[idx] <= sum) pick = dp[idx-1][sum-arr[idx]];

                    dp[idx][sum] = (pick + not_pick);
            }
        }
                        
        return dp[n-1][tar];
    }
    */

   // Space Optimization
    int countPartitions(int n, int target, vector<int> &arr) 
    {
        int tot_sum = 0;
        for(auto i = 0; i < n; i++)
            tot_sum += arr[i];
        
        if((tot_sum-target) < 0 || (tot_sum-target)%2) return 0;
        
        int tar = (tot_sum-target)/2;
        vector<int> prev(tar+1, 0);
        vector<int> curr(tar+1, 0);
        
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        if(arr[0] != 0 && arr[0] <= tar) prev[arr[0]] = 1;
                        
        for(int idx = 1; idx < n; idx++)
        {
            for(int sum = 0; sum <= tar; sum++)
            {
                    int not_pick = prev[sum];
                    int pick = 0;
                    if(arr[idx] <= sum) pick = prev[sum-arr[idx]];

                    curr[sum] = (pick + not_pick);
            }
            prev = curr;
        }
                        
        return prev[tar];
    }
};

int main() 
{ 
        int N, target;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin>>target;
        Solution ob;
        cout<<ob.countPartitions(N, target, arr)<<endl;
    return 0; 
} 