// problem statement: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1/#

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[N+1][W+1];
        for(int i = 0; i <= N; i++)
        {
            for(int j = 0; j <= W; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i<= N; i++)
        {
            for(int j = 1; j <= W; j++)
            {
                if(wt[i-1] <= j)
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][W];
    }
};


int main()
{
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    return 0;
}