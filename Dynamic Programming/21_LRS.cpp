// Longest Repeating Subsequence
// Problem Statement: https://www.geeksforgeeks.org/longest-repeated-subsequence/


#include<bits/stdc++.h>
using namespace std;


class Solution {
	public:
	int LongestRepeatingSubsequence(string a)
          {
                    
		string b = a;
		int n = a.size();
		int dp[n+1][n+1];
		    
		for(int i = 0; i <= n; i++)
		{
		 for(int j = 0; j <= n; j++)
		 {
		       if(i == 0 || j == 0)
		           dp[i][j] = 0;
		  }
		}
		    
		for(int i = 1; i <= n; i++)
		{
		        for(int j = 1; j <= n; j++)
		        {
                                // If characters match and indexes are not same
		            if((a[i-1] == b[j-1]) && (i != j))
		                dp[i][j] = 1+dp[i-1][j-1];
		            else
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		        }
		}
		    
		return dp[n][n];
	}
};
int main()
{
          string str;
	cin >> str;
	Solution obj;
	int ans = obj.LongestRepeatingSubsequence(str);
	cout << ans << "\n";
	return 0;
}  

// Time Complexity: O(n^2)
// Auxiliary Space: O(n^2)