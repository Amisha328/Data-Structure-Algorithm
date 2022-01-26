// Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both,
// X and Y as its sub-sequences.

// Problem linK: https://www.geeksforgeeks.org/shortest-common-supersequence/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int lcs(string &X, string &Y, int m, int n)
    {
        int dp[m+1][n+1];
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(X[i-1] == Y[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return (m+n)-lcs(X, Y, m, n);
    }
};

int main()
{   
    string X, Y;
    cin >> X >> Y;
    Solution obj;
    cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    return 0;
}

// Time Complexity: O(Length(X) * Length(Y)).
// Auxiliary Space: O(Length(X) * Length(Y)).