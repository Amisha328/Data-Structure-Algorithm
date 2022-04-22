// Same as 02_SubsetSumProblem but array can contain zero element that can form the subset
// Problem link: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

#include<bits/stdc++.h> 
using namespace std; 


class Solution
{
	public:
          /*
          // Memoization:
	int mod = 1e9 + 7;
	int solve(int num[], int idx, int sum, vector<vector<int>> &dp)
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
	int perfectSum(int arr[], int n, int sum)
	{
                    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
                    return solve(arr, n-1, sum, dp)%mod;
        
	}
          */

         // Tabulation:
          int perfectSum(int arr[], int n, int tar)
	{
                    vector<vector<int>> dp(n, vector<int>(tar+1, 0));

                    // if arr[0] is equal to zero and sum is equal to zero then 2 choice either take or not take no effect
                    if(arr[0] == 0) dp[0][0] = 2;
                    // if arr[0] is not zero and sum is equal to zero then only one choice not take
                    else dp[0][0] = 1;
                    
                    // if arr[0] == sum then one chice to take it given that arr[0] should not be zero as if arr[0] = 0 and sum != 0
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

};
int main() 
{ 
        int N, sum;
        cin >> N >> sum;
       int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.perfectSum(arr, N, sum) << endl;
    return 0; 
} 