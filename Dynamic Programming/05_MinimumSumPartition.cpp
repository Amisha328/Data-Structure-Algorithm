// Problem: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
// Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 
// such that the absolute difference between their sums is minimum and find the minimum difference

#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
	int minDifference(int arr[], int N)  { 
	    // Your code goes here
	    int sum = accumulate(arr, arr+N, 0LL);
	    bool dp[N+1][sum+1];
	    vector<int> v(sum/2);
	    int mn = INT_MAX;
	    for(int i = 0; i <= N; i++)
	    {
	        for(int j = 0; j <= sum; j++)
	        {
	            if(i == 0)
	                dp[i][j] = false;
	            if(j == 0)
	                dp[i][j] = true;
	        }
	    }
	    
	    for(int i = 1; i <= N; i++)
	    {
	        for(int j = 1; j <= sum; j++)
	        {
	            if(arr[i-1] <= j)
	                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	  
	    for(int i = 0; i <= sum/2; i++)
	    {
	        if(dp[N][i])
	            v.push_back(i);
	    }
	    
	    
	    for(int i = 0; i < v.size(); i++)
	    {
	        mn = min(mn, sum-2*v[i]);
	    }
	    
	    return mn;
	} 
};

int main() 
{
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];
        Solution ob;
        cout << ob.minDifference(a, n) << "\n";

    return 0;
}  

// Expected Time Complexity: O(N*|sum of array elements|)
// Expected Auxiliary Space: O(N*|sum of array elements|)