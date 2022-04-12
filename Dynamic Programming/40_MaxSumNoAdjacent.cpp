// Maximum sum such that no two elements are adjacent
// Problem statement: https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
// Problem link: https://leetcode.com/problems/house-robber/
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int arr[], int n) {

	    // Time Complexity: O(n)
              // Auxilary Space: O(n)
	    int dp[n+1];
	    if(n == 1) return arr[0];
	    dp[1] = arr[0];
	    dp[2] = max(arr[0], arr[1]);
	    
	    for(int i = 3; i <= n; i++)
	    {
	        dp[i] = max(dp[i-1], dp[i-2]+arr[i-1]);
	    }
	    
	    return dp[n];


	    /*
              // Optimizing the space complexity by the concept of fibonacci series concept
              // Time Complexity: O(n)
              // Auxilary Space: O(1)
	    if(n == 1) return arr[0];
	    
	    int prev_prev = arr[0];
	    int prev = max(arr[0], arr[1]);
	    
	    int res = prev;
	    for(int i = 3; i <= n; i++)
	    {
	        res = max(prev, prev_prev+arr[i-1]);
	        prev_prev = prev;
	        prev = res;
	    }
	    
	    return res;
	    */
	    
              
	}
};

// { Driver Code Starts.

int main() {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    return 0;
} 