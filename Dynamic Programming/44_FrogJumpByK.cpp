//  Frog Jump with K Distance
// Problem link: https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
          /*
          // Memoization: TC->O(n*k) | SC -> O(n) + O(n)
          int solve(vector<int> &h, int n, vector<int> &dp, int k)
          {
                    if(n == 0) return 0;
                    if(dp[n] != -1) return dp[n];
                    int min_step = INT_MAX;
                    for(int i = 1; i <= k; i++)
                    {
                              if(n-i >= 0)
                              {
                                        int jump = solve(h, n-i, dp, k) + abs(h[n]-h[n-i]);
                                         min_step = min(min_step, jump);
                              }
                    }
                    return dp[n] = min_step;
          }
          int frogJump(int n, vector<int> &heights, int k)
          {
                    // Write your code here.
                    vector<int> dp(n, -1);
                    return solve(heights, n-1, dp, k);
          }
          */

          // Tabulation : TC -> O(n*k) | SC -> O(n)
          int frogJump(int n, vector<int> &h, int k)
          {
                    // Write your code here.
                    vector<int> dp(n, -1);
                    dp[0] = 0;
                    int min_step;
                    for(int i = 1; i < n; i++)
                    {
                            min_step = INT_MAX;
                            for(int j = 1; j <= k; j++)
                            {
                                      if(i-j >= 0)
                                      {
                                                int jump = dp[i-j] + abs(h[i]-h[i-j]);
                                                min_step = min(min_step, jump);
                                      }
                            }  
                            dp[i] = min_step;
                    }

                    return dp[n-1];   
          }

};

int main()
{
          int n, k;
          cin>>n>>k;
          vector<int> height(n);
          for(int i = 0; i < n; i++)
          cin>>height[i];
          Solution ob;
          cout<<ob.frogJump(n,height,k)<<endl;
          return 0;
}