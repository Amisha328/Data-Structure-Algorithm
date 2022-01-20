// Count the number of subset with a given difference

#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
    int countSubsetSum(int N, int arr[], int sum)
    {
       
       int  dp[N+1][sum+1];
       
       for(int i = 0; i < N+1; i++)
       {
           for(int j =0; j < sum+1; j++)
           {
               if(i == 0)
                dp[i][j] = 0;
               if(j == 0)
                dp[i][j] = 1;
           }
       }
        
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][sum];
           
    }

    int countWithGivenDiff(int N, int arr[], int diff)
    {
          int sum = accumulate(arr, arr+N, 0LL);
          int s1 = (diff+sum)/2;
          return countSubsetSum(N, arr, s1);
    }
};

int main() 
{ 
        int N, diff;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin>>diff;
        Solution ob;
        cout << ob.countWithGivenDiff(N, arr, diff) << endl;
    return 0; 
} 


// Expected Time Complexity: O(sum*N)
// Expected Auxiliary Space: O(sum*N)