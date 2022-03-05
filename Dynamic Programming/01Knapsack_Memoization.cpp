#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
      // Striver Solution:
      // // TC->O(N*maxWeight) | SC->O(N*maxWeight) + O(N)
      int solve(vector<int> &weight, vector<int> &value, int idx, int W, vector<vector<int>> &dp)
      {
          if(idx == 0)
          {
              if(weight[0] <= W) return value[0];
              else return 0;
          }
          if(dp[idx][W] != -1) return dp[idx][W];
          
          int not_take = 0 + solve(weight, value, idx-1, W, dp);
          int take = -1e3;
          if(weight[idx] <= W) 
              take = value[idx] + solve(weight, value, idx-1, W-weight[idx], dp);
          
          return dp[idx][W] = max(take, not_take);
      }
      int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
      {
          vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
          return solve(weight, value, n-1, maxWeight, dp);
      }
      
    /*
    // Aditya Verma Solution:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSackRec(int W, int wt[], int val[], int n, int** dp)
    {
          // base condition
          if (n == 0 || W == 0)
             return 0;
          if (dp[n][W] != -1)
            return dp[n][W];
          
          if (wt[n-1] <= W) 
            dp[n][W] = max(val[n-1] + knapSackRec(W - wt[n-1], wt, val, n - 1, dp), knapSackRec(W, wt, val, n - 1, dp));
          else
            dp[n][W] = knapSackRec(W, wt, val, n - 1, dp);

          return dp[n][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
          int** dp;
          dp = new int*[n+1];
          
          // loop to create the table dynamically
          for (int i = 0; i < n+1; i++)
          dp[i] = new int[W + 1];
          
          // loop to initially filled the
          // table with -1
          for (int i = 0; i < n+1; i++)
            for (int j = 0; j < W + 1; j++)
                    dp[i][j] = -1;
          
          return knapSackRec(W, wt, val, n, dp);
       
    }
    */


};

// { Driver Code Starts.

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
