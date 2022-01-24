// Longest Common Subsequence - Memoization (bottom-up) approach

// Problem Statement: https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;


static int dp[1001][1001];
int lcs(string &text1, string &text2, int n, int m)
{
        if(n == 0 || m == 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(text1[n-1] == text2[m-1])
            return dp[n][m] = 1+lcs(text1, text2, n-1, m-1);
        else
            return dp[n][m] = max(lcs(text1, text2, n-1, m), lcs(text1, text2, n, m-1));
}

int main()
 {
        //reading number of elements and weight
        string text1, text2;
          cin>>text1>>text2;
          int n = text1.size();
          int m = text2.size();

          memset(dp, -1, sizeof(dp));
          cout<<lcs(text1, text2, n, m)<<endl;
                 
        return 0;
} 

// Time Complexity: O(n*m).
// Auxiliary Space: O(n*m)
