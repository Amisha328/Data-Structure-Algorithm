#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
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
};

// { Driver Code Starts.

int main()
 {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
        return 0;
} 

// Expected Time Complexity: O(N*W).
// Expected Auxiliary Space: O(N*W)