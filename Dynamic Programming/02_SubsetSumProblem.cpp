// Given an array of non-negative integers,
// and a value sum, determine if there is a subset of the given set with sum equal to given sum.
// problem link: https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1# 

#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
    /*
    // Memoization: TC->O(N*sum) | SC->O(N*sum)+O(N)
    int solve(vector<int> &num, int idx, int sum, vector<vector<int>> &dp)
    {
        if(sum == 0) return 1;
        if(idx == 0) return (num[idx] == sum);
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int not_pick = solve(num, idx-1, sum, dp);
        int pick = 0;
        if(num[idx] <= sum) pick = solve(num, idx-1, sum-num[idx], dp);
        
        return dp[idx][sum] = (pick + not_pick);
    }
    int isSubsetSum(vector<int> &num, int tar)
    {
        // Write your code here.
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, 0));
        return solve(num, n-1, tar, dp);
    }
    */

   /*
   // Tabulation: TC->O(N*sum) | SC->O(N*sum)
   int isSubsetSum(vector<int> &num, int tar)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, 0));

        for(int idx = 0; idx < n; idx++)
        dp[idx][0] = 1;
    
        if(num[0] <= tar) dp[0][num[0]] = 1;
        
        for(int idx = 1; idx < n; idx++)
        {
            for(int sum = 0; sum <= tar; sum++)
            {
                int not_pick = dp[idx-1][sum];
                int pick = 0;
                if(num[idx] <= sum) pick = dp[idx-1][sum-num[idx]];

                dp[idx][sum] = (pick + not_pick);
            }
        }
        
        return dp[n-1][tar];
    }
    */

    // Sapce Optimization: TC->O(N*sum) | SC->O(sum)
    int isSubsetSum(vector<int> &num, int tar)
    {
        int n = num.size();
        vector<int> prev(tar+1, 0);
        vector<int> curr(tar+1, 0);

        for(int idx = 0; idx < n; idx++)
        prev[0] = 1;
    
        if(num[0] <= tar) prev[num[0]] = 1;
        
        for(int idx = 1; idx < n; idx++)
        {
            for(int sum = 0; sum <= tar; sum++)
            {
                int not_pick = prev[sum];
                int pick = 0;
                if(num[idx] <= sum) pick = prev[sum-num[idx]];

                curr[sum] = (pick + not_pick);
            }
            prev = curr;
        }
        
        return prev[tar];
    }

};
int main() 
{ 
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    return 0; 
} 
