// Minimum number of deletions to make a sorted sequence
// variation of Longest Increasing Subsequence
// Problem Statement: https://www.geeksforgeeks.org/minimum-number-deletions-make-sorted-sequence/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
   public:
   int LIS(int nums[], int n)
   {
	int lis[n];
	lis[0] = 1;
	for(int i = 1; i < n; i++)
          {
                    lis[i] = 1;
                    for(int j = 0; j < i; j++)
                    {
                              if(nums[j] < nums[i])
                                        lis[i] = max(lis[i], lis[j]+1);
                    }
          }
          return *max_element(lis, lis+n);
  }
 int minDeletions(int arr[], int n) 
 { 
	    
	return (n-LIS(arr,n));
 } 
};


int main() 
{
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	Solution ob;
	cout << ob.minDeletions(arr, n) << "\n";
    return 0;
}

// time complexity: O(n^2)
// space complexity: O(n)