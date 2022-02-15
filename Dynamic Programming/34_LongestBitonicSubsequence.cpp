// Longest Bitonic subsequence  - Problems based on the Longest Increasing Subsequence concept.
// Problem Statement: https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
// Problem linK: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/


#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    int lis[n], lds[n];
	    
	    lis[0] = 1;
	    lds[n-1] = 1;
	    
	    for(int i = 1; i < n; i++)
	    {
	        lis[i] = 1;
	        for(int j = 0; j < i; j++)
	        {
	            if(nums[j] < nums[i])
	                lis[i] = max(lis[i], lis[j]+1);
	        }
	    }
	     for(int i = n-2; i >= 0; i--)
	     {
	         lds[i] = 1;
	        for(int j = n-1; j > i; j--)
	        {
	            if(nums[j] < nums[i])
	                lds[i] = max(lds[i], lds[j]+1);
	        }
	    }
	    
	    int ans = 0;
	    for(int i = 0; i < n; i++)
	    {
	        ans = max(ans, lis[i]+lds[i]-1);
	    }
	    
	    return ans;
	}
};

int main()
{

	int n;
	cin >> n;
	vector<int>nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	Solution ob;
	int ans = ob.LongestBitonicSequence(nums);
	cout << ans <<"\n";
	return 0;
} 

// Time Complexity: O(n^2)
// Space Complexity: O(n)