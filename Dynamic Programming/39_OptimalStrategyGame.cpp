// Optimal Strategy for a Game
// Problem link: https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
// https://leetcode.com/problems/predict-the-winner/submissions/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum possible amount of money we can win.
class Solution
{
    public:
    // Memoization method
    long long dp[21][21];
    long long solve(int arr[], int n, int i, int j)
    {
        // below diagonal values zero
        if(i > j)
            return 0;
        // filling the central diagonal value
        if(i == j)
            dp[i][j] = arr[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // case 1: if you have picked arr[i]
        // Then your opponent can pick either i+1 or j. If he/she picks
        //  i+1 -> choices left for you are i+2 or j
        //  j -> choices left you you are i+1 or j-1
        // Now, since your opponent is playing as smartly as you are he/she will pick i+1 or j
        // such that you can get min choice options in your turn.
        long long int front_pick = arr[i]+ min(solve(arr,n,i+2,j), solve(arr,n,i+1,j-1));
        
        // case 2: if you have picked arr[j]
        // Then your opponent can pick either i or j-1. If he/she picks
        //  i -> choices left for you are i+1 or j-1
        //  j-1 -> choices left you you are i or j-2
        // Now, since your opponent is playing as smartly as you are he/she will pick i or j-1
        // such that you can get min choice options in your turn.
        long long int back_pick = arr[j]+ min(solve(arr,n,i,j-2), solve(arr,n,i+1,j-1));
        
        return dp[i][j] = max(front_pick, back_pick);
        
    }
    long long maximumAmount(int arr[], int n){
        memset(dp, -1, sizeof(dp));
        return solve(arr, n, 0, n-1);
        
    }
};

/* 
    // Tabulation solution
    long long maximumAmount(int arr[], int n)
    { 
        long long dp[n][n];
        for(auto i = 0; i < n; i++)
            dp[i][i+1] = max(arr[i],arr[i+1]);
        
        for(auto gap = 3; gap < n; gap += 2)
        {
            for(auto i = 0; i+gap < n; i++)
            {
                long long j = i+gap;
                dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]), 
                               arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
            }
        }
        
        return dp[0][n-1];
    }
};
*/

int main() 
{
	int n;
	cin>>n;
          //cout<<n<<" ";
	int a[n];
	for(int i = 0; i < n; i++)
	          cin >> a[i];
	Solution ob;
	cout<< ob.maximumAmount(a,n)<<endl;
	return 0;
}


// Time Complexity: O(n^2)
// Auxilary Space: O(n^2)