// Matrix Chain Multiplication - Memoization approach
// problem statement: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dp[101][101];
    int solve(int arr[], int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i; k < j; k++)
        {
            int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            ans = min(ans, temp_ans);
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, N-1);
    }
};

int main()
{
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    return 0;
}