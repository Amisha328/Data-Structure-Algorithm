// Minimum number of deletions and insertions
// Problem Statement: https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	int longestCommonSubsequence(string &str1, string &str2)
	{
	    int n = str1.size();
	    int m = str2.size();
	    
	    int dp[n+1][m+1];
	    
	    for(int i = 0; i <= n; i++)
	    {
	        for(int j =0; j <= m; j++)
	        {
	            if(i == 0 || j == 0)
	                dp[i][j] = 0;
	        }
	    }
	    
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= m; j++)
	        {
	            if(str1[i-1] == str2[j-1])
	                dp[i][j] = 1 + dp[i-1][j-1];
	            else
	                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	        }
	    }
	    
	    return dp[n][m];
	}
	int minOperations(string str1, string str2) 
	{ 
	    int lcs = longestCommonSubsequence(str1, str2);
              // Deletion + Insertion
	    return (str1.size()-lcs)+(str2.size()-lcs);   
	} 
};


int main() 
{
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";
    return 0;
}

// Time Complexity: O(|str1|*|str2|)
// Space Complexity: O(|str1|*|str2|)