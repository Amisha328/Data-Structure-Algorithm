// Given an array of non-negative integers,
// and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum)
    {
        // code here 
        bool dp[N+1][sum+1];
       
       for(int i = 0; i < N+1; i++)
       {
           for(int j =0; j < sum+1; j++)
           {
               if(i == 0)
                dp[i][j] = false;
               if(j == 0)
                dp[i][j] = true;
           }
       }
        
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][sum];
           
    }
};

int main() 
{ 
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    return 0; 
} 


// Expected Time Complexity: O(sum*N)
// Expected Auxiliary Space: O(sum*N)