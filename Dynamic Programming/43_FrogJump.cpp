// Problem Statement: https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/
// There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. 
// HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump
// is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to 
// (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from
// 1st stair to Nth stair.


// Problem link: https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
          /*
          // Memoization: TC->O(n) | SC -> O(n) + O(n)
          int solve(vector<int> &h, int n, vector<int> &dp)
          {
                    if(n == 0) return 0;
                    if(dp[n] != -1) return dp[n];
                    int one_step = solve(h, n-1, dp) + abs(h[n]-h[n-1]);
                    int two_step = INT_MAX;
                    if(n > 1)
                              two_step = solve(h, n-2, dp) + abs(h[n]-h[n-2]);
                    
                    return dp[n] = min(one_step, two_step);
          }
          int frogJump(int n, vector<int> &heights)
          {
                    // Write your code here.
                    vector<int> dp(n, -1);
                    return solve(heights, n-1, dp);
          }
          */
          // Tabulation : TC -> O(n) | SC -> O(n)
          int frogJump(int n, vector<int> &h)
          {
                    // Write your code here.
                    vector<int> dp(n, -1);
                    dp[0] = 0;
                    for(int i = 1; i < n; i++)
                    {
                              int one_step = dp[i-1] + abs(h[i]-h[i-1]);
                              int two_step = INT_MAX;
                              if(i > 1)
                                        two_step = dp[i-2] + abs(h[i]-h[i-2]);
                              
                              dp[i] = min(one_step, two_step);
                    }

                    return dp[n-1];   
          }
};

int main()
{
          int n;
          cin>>n;
          vector<int> height(n);
          for(int i = 0; i < n; i++)
          cin>>height[i];
          Solution ob;
          cout<<ob.frogJump(n,height)<<endl;
          return 0;
}