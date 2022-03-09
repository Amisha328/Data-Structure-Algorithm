// Longest Common Subsequence - Space Optimization

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
        
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int i = 0; i <= n; i++)
            prev[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        return prev[m];
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
// Expected Auxiliary Space: O(m).
