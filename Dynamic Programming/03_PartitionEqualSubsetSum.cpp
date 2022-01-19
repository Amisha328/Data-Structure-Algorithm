// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements
// in both parts is the same.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool subsetSum(int N, int arr[], int sum)
    {
        bool dp[N+1][sum+1];
        for(int i = 0; i < N+1; i++)
        {
            for(int j = 0; j < sum+1; j++)
            {
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;
            }
        }
        
        for(int i = 1; i < N+1; i++)
        {
            for(int j = 1; j < sum+1; j++)
            {
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][sum];
    }
    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr, arr+N, 0LL);
        if(sum % 2 != 0)
            return 0;
        else
            return subsetSum(N, arr, sum/2);
    }
};

int main()
{
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    return 0;
}