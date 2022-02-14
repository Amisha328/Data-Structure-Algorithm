// Maximum Sum Increasing Subsequence - variation of Longest Increasing Subsequence
// Problem Statement: https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
// Problem link: https://leetcode.com/problems/best-team-with-no-conflicts/


#include <bits/stdc++.h>
using namespace std;

class Solution
{	
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int msum[n];
	    msum[0] = arr[0];
	    for(int i = 1; i < n; i++)
	    {
	        msum[i] = arr[i];
	        for(int j = 0; j < i; j++)
	        {
	            if(arr[i] >= arr[j])
	                msum[i] = max(msum[i], msum[j]+arr[i]);
	        }
	    }
	    
	    return *max_element(msum, msum+n);
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
	cout << ob.maxSumIS(a, n) << "\n";
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)