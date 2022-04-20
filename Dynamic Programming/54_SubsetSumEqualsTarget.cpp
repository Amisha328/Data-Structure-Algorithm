// Subset Sum Equals to Target
// Problem link: https://www.codingninjas.com/codestudio/problem-details/subset-sum-equal-to-k_1550954

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
          /*
          // Memoization: TC -> O(n*target) | SC -> O(n*target) + O(n)
          bool solve(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
          {
                    if(target == 0) return true;
                    if(idx == 0) return (arr[0] == target);
                    
                    if(dp[idx][target] != -1) return dp[idx][target];
                    
                    bool not_take = solve(idx-1, target, arr, dp);
                    bool take = false;
                    if(target >= arr[idx])
                    take = solve(idx-1, target-arr[idx], arr, dp);
                    
                    return dp[idx][target] = (not_take | take);
          }
          bool subsetSumToK(int n, int k, vector<int> &arr) 
          {
                    vector<vector<int>> dp(n, vector<int>(k+1, -1));
                    return solve(n-1, k, arr, dp);
          }
          */

         /*
         // Tabulation:  TC -> O(n*target) | SC -> O(n*target)
         bool subsetSumToK(int n, int k, vector<int> &arr) 
         {
                    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
                    
                    for(int idx = 0; idx < n; idx++)  dp[idx][0] = true;
                    if(arr[0] <= k) dp[0][arr[0]] = true;
                    
                    for(int idx = 1; idx < n; idx++)
                    {
                              for(int target = 1; target <= k; target++)
                              {
                                        bool not_take = dp[idx-1][target];
                                        bool take = false;
                                        if(target >= arr[idx])
                                        take = dp[idx-1][target-arr[idx]];

                                        dp[idx][target] = (not_take | take);
                              }
                    }
          
                    return dp[n-1][k];
          }
          */

         // Space Optimized solution: TC -> O(n*target) | SC -> O(target)
         bool subsetSumToK(int n, int k, vector<int> &arr) 
         {
                   vector<bool> prev(k+1, 0), curr(k+1, 0);
                    prev[0] = curr[0] = true;
                    if(arr[0] <= k) prev[arr[0]] = true;
                    for(int idx = 1; idx < n; idx++)
                    {
                              for(int target = 1; target <= k; target++)
                              {
                                        bool not_take = prev[target];
                                        bool take = false;
                                        if(target >= arr[idx])
                                        take = prev[target-arr[idx]];

                                        curr[target] = (not_take | take);
                              }
                    
                              prev = curr;
                    }
                    
                    return prev[k];
          }
};

int main() 
{
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;
        cout << ob.subsetSumToK(n, k, a) << endl;
    return 0;
}  