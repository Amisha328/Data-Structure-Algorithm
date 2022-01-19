// Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with 
// a sum equal to a given sum.
// Note: Answer can be very large, so, output answer modulo 109+7

#include <bits/stdc++.h>
using namespace std;

class Solution{

    public:
    int perfectSum(int arr[], int n, int sum)
   {
        // Your code goes here
        int dp[n+1][sum+1];
        long long int mod = 1e9+7;
        
        // Here we dont have to set t[i][0] = 1 for all i because for j=0 (i.e sum=0) subset with value zeros [0,0,0]
        // can be formed and that is get counted here; only initialize dp[0][0]=1;
        dp[0][0] = 1;
        for(int i = 1;i < sum+1; i++)
            dp[0][i] = 0;
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 0; j < sum+1; j++)
            {
                if(arr[i-1] <= j)
                    dp[i][j] = (dp[i-1][j]%mod + dp[i-1][j-arr[i-1]]%mod)%mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
      }
	  
};

int main() 
{
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];
        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    return 0;
}


// Expected Time Complexity: O(N*sum)
// Expected Auxiliary Space: O(N*sum)

// Problem link: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#