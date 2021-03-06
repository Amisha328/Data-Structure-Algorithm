// Longest Common Subsequence - Tabulation (Bottom-up approach)

// Problem Statement: https://leetcode.com/problems/longest-common-subsequence/
// https://www.codingninjas.com/codestudio/problem-details/longest-common-subsequence_1063255

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
     int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size();
        int m = text2.size();
        
        int dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= m; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};

int main()
{
          string text1, text2;
          getline(cin, text1);
          getline(cin, text2);

          Solution obj;
          cout<<obj.longestCommonSubsequence(text1, text2)<<endl;

}

// Expected Time Complexity: O(n*m).
// Expected Auxiliary Space: O(n*m).
