// Matrix Chain Multiplication - Memoization approach
// problem statement: 
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// https://www.codingninjas.com/codestudio/problem-details/matrix-chain-multiplication_975344

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr, int N)
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(1, N-1, arr, dp);
    }
};

int main()
{
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(arr, N)<<endl;
    return 0;
}
