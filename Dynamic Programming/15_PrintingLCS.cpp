// Printing Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size();
        int m = text2.size();
        
        int dp[n+1][m+1];
        
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
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i = n, j = m;
        string str;
        while(i > 0 && j > 0)
        {
            if(text1[i-1] == text2[j-1])
            {
                str.push_back(text1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }

        reverse(str.begin(), str.end());
        return str;
        
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