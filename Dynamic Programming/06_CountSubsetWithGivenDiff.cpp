// Count the number of subset with a given difference
// s1 is first subset and s2 is the second subset
// Constraint: s1 >= s2 and s1-s2 = D (given differnece)
// Problem statement: https://www.codingninjas.com/codestudio/problem-details/partitions-with-given-difference_3751628

#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
/*
    // Memoization:
    int mod = (int)(1e9+7);
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
            
            return dp[idx][sum] = (pick + not_pick)%mod;
    }
    int countPartitions(int n, int d, vector<int> &arr) {
        int tot_sum = 0;
        for(auto i = 0; i < n; i++)
            tot_sum += arr[i];
        
        if((tot_sum-d) < 0 || (tot_sum-d)%2) return 0;
        
        int tar = (tot_sum-d)/2;
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        return solve(arr, n-1, tar, dp)%mod;
    }
    */


    /*
    // Tabulation:
    int countPartitions(int n, int d, vector<int> &arr) 
    {
        int mod = (int)(1e9+7);
        int tot_sum = 0;
        for(auto i = 0; i < n; i++)
            tot_sum += arr[i];
        
        if((tot_sum-d) < 0 || (tot_sum-d)%2) return 0;
        
        int tar = (tot_sum-d)/2;
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

                    dp[idx][sum] = (pick + not_pick)%mod;
            }
        }
                        
        return dp[n-1][tar]%mod;
    }
    */

   // Space Optimization
    int countPartitions(int n, int d, vector<int> &arr) 
    {
        int mod = (int)(1e9+7);
        int tot_sum = 0;
        for(auto i = 0; i < n; i++)
            tot_sum += arr[i];
        
        if((tot_sum-d) < 0 || (tot_sum-d)%2) return 0;
        
        int tar = (tot_sum-d)/2;
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

                    curr[sum] = (pick + not_pick)%mod;
            }
            prev = curr;
        }
                        
        return prev[tar]%mod;
    }
};
int main() 
{ 
        int N, diff;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin>>diff;
        Solution ob;
        cout<<ob.countPartitions(N, diff, arr)<<endl;
    return 0; 
} 
