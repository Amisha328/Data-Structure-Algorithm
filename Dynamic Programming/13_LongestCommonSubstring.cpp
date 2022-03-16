// Longest Common Substring 
// Problem Statement: https://www.geeksforgeeks.org/longest-common-substring/
// https://www.codingninjas.com/codestudio/problem-details/longest-common-substring_1235207


#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // Tabulation: TC -> O(n*m) | SC -> O(n*m)
    /*
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        int dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        } 
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                          dp[i][j] = 1 + dp[i-1][j-1];
                          // longest common substring can exist anywhere in between
                          ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        // we have to return the max value in the matrix and not dp[n][m]
        return ans;

    }
    */
       // Space Optimization: TC -> O(n*m) | SC -> O(m)
       int longestCommonSubstr (string &str1, string &str2)
       {
        int n = str1.size();
        int m = str2.size();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        /*
        // We can ommit this part as well as we have initialized the entire matrix as zero initially
        for(int i = 0; i <= n; i++)
            prev[0] = 0;
        for(int i = 0; i <= m; i++)
            prev[i] = 0;
        */
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                    ans = max(ans, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            prev = curr;
        }
        return ans;
    }

};


int main()
{
        int n, m; 
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
}
