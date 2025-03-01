// Longest Bitonic subsequence  - Problems based on the Longest Increasing Subsequence concept.
// Problem Statement: https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
// Problem linK: 
// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?leftPanelTab=0
// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1


#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	
	int LongestBitonicSequence(vector<int>nums)
	{
	   int n = nums.size();
	   vector<int> dp1(n, 1);
	   for(int i = 0; i < n; i++){
	       for(int prev = 0; prev < i; prev++){
	           if(nums[i] > nums[prev] && 1 + dp1[prev] > dp1[i]){
	               dp1[i] = 1 + dp1[prev];
	           }
	       }
	   }
	   vector<int> dp2(n, 1);
	   for(int i = n-1; i >= 0; i--){
	       for(int prev = n-1; prev > i; prev--){
	           if(nums[i] > nums[prev] && 1 + dp2[prev] > dp2[i]){
	               dp2[i] = 1 + dp2[prev];
	           }
	       }
	   }
	   int ans = 0;
	   for(int i = 0; i < n; i++){
	       ans = max(ans, dp1[i]+dp2[i]-1);
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
