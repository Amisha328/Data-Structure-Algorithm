// problem statement: 
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1/#
// https://www.codingninjas.com/codestudio/problem-details/unbounded-knapsack_1215029

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    /*
    // Memoization: TC-> O(N * W) | SC-> O(N * W) + O(N)
    int solve(int idx, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if(idx == 0)
            return (w/wt[0])*val[0];
        if(dp[idx][w] != -1) return dp[idx][w];
        int not_take = 0 + solve(idx-1, w, val, wt, dp);
        int take = 0;
        if(wt[idx] <= w)
            take = val[idx] + solve(idx, w-wt[idx], val, wt, dp);
        
        return dp[idx][w] = max(take, not_take);
    }
    int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
    {
        vector<vector<int>> dp(n, vector<int>(w+1, -1));
        return solve(n-1, w, val, wt, dp);
    }
    */

    /*
    // Tabulation: TC-> O(N * W) | SC-> O(N * W)
    int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
    {
        vector<vector<int>> dp(n, vector<int>(w+1, 0));
        for(int W = 0; W <= w; W++)
            dp[0][W] = (W/wt[0])*val[0];
        for(int idx = 1; idx < n; idx++)
        {
            for(int W = 0; W <= w; W++)
            {
                int not_take = 0 + dp[idx-1][W];
                int take = 0;
                if(wt[idx] <= W)
                    take = val[idx] + dp[idx][W-wt[idx]];

                dp[idx][W] = max(take, not_take);
            }
        }
        return dp[n-1][w];
    }
    */

    /*
    // Space Optimization: TC-> O(N * W) | SC-> O(2 * W)
    int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
    {
        vector<int> prev(w+1, 0);
        vector<int> curr(w+1, 0);
        for(int W = 0; W <= w; W++)
            prev[W] = (W/wt[0])*val[0];
        for(int idx = 1; idx < n; idx++)
        {
            for(int W = 0; W <= w; W++)
            {
                int not_take = 0 + prev[W];
                int take = 0;
                if(wt[idx] <= W)
                    take = val[idx] + curr[W-wt[idx]];

                curr[W] = max(take, not_take);
            }
            prev = curr;
        }
        return prev[w];
    }
    */
   
   // Most optimized code: TC-> O(N * W) | SC-> O(W)
   int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
    {
        vector<int> curr(w+1, 0);
        for(int W = 0; W <= w; W++)
            curr[W] = (W/wt[0])*val[0];
        for(int idx = 1; idx < n; idx++)
        {
            for(int W = 0; W <= w; W++)
            {
                int not_take = 0 + curr[W];
                int take = 0;
                if(wt[idx] <= W)
                    take = val[idx] + curr[W-wt[idx]];

                curr[W] = max(take, not_take);
            }
        }
        return curr[w];
    }
};


int main()
{
        int N, W;
        cin>>N>>W;
        vector<int> val(N), wt(N);
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.unboundedKnapsack(N, W, val, wt)<<endl;
    return 0;
}
