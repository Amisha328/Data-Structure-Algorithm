// Problem link: 
// https://www.codingninjas.com/codestudio/problem-details/0-1-knapsack_920542
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    // Striver Solution:
    // TC->O(N*maxWeight) | SC->O(N*maxWeight) 
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
    {
        vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
        for(int i = weight[0]; i <= maxWeight; i++)
            dp[0][i] = value[0];
        
        for(int idx = 1; idx < n; idx++)
        {
            for(int wt = 0; wt <= maxWeight; wt++)
            {
                int not_take = 0 + dp[idx-1][wt];
                int take = INT_MIN;
                if(weight[idx] <= wt) 
                    take = value[idx] + dp[idx-1][wt-weight[idx]];

                dp[idx][wt] = max(take, not_take);
            }
        }
        return dp[n-1][maxWeight];
    }
    /*
    // Aditya Verma Solution:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
          int t[n+1][W+1];
          memset(t,-1,sizeof(t));
          for(int i = 0; i < n+1; i++)
          {
                    for(int j = 0; j < W+1; j++)
                    {
                              if(i == 0 || j == 0)
                                        t[i][j] = 0;
                    }
          }  
          for(int i = 1; i < n+1; i++)
          {
                    for(int j = 1; j < W+1; j++)
                    {
                                        
                              if(wt[i-1] <= j)
                                        t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
                              else
                                        t[i][j] = t[i-1][j];
                    }
          }  

          return t[n][W];     
    }
    */
};

int main()
 {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        vector<int> wt(n);
        vector<int> val(n);
        
        //inserting the values
        for(int i = 0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapsack(wt, val, n, w)<<endl;
        
        return 0;
} 

