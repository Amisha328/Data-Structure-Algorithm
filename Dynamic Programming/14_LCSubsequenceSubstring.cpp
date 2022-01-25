// Substring - Subsequence problem
// Find the longest subsequence X of a string A which is a substring Y of a string B.
// Problem link: https://practice.geeksforgeeks.org/problems/substring-subsequence-problem1631/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLongestSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        
        int dp[n+1][m+1];
        
        int ans = 0;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return ans;
    }
};

int main() 
{
        string A,B;
        cin >>A>>B;
        Solution ob;
        cout << ob.getLongestSubsequence(A,B) << endl;
    return 0;
}  