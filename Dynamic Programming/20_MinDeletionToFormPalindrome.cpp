// Minimum number of deletions to make a string palindrome
// Problem statement: https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/

#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minDeletions(string A) 
    {
        string B = A;
        reverse(B.begin(), B.end());
        
        int n = A.size();
        
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
                if(A[i-1] == B[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return (n-dp[n][n]);
    }
};

int main()
{
    string s; cin >> s;
    Solution ob;
    cout << ob.minDeletions(s) << endl;
}


