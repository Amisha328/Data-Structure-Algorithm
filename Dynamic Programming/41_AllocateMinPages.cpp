// Allocate minimum number of pages
// Problem link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

int sum(int arr[],int b, int e){
    int s = 0;
    for(int i = b;i <= e;i++)
        s += arr[i];
    return s;
}

int minPages(int arr[],int n, int k){
    int dp[k+1][n+1];
    for(int i = 1; i <= n; i++)
        dp[1][i] = sum(arr,0,i-1);
    for(int i = 1; i <= k; i++)
        dp[i][1] = arr[0];
        
    for(int i = 2;i <= k; i++){
        for(int j = 2; j <= n; j++){
            int res=INT_MAX;
            for(int p = 1; p < j; p++){
                res=min(res,max(dp[i-1][p],sum(arr,p,j-1)));
            }
            dp[i][j]=res;
        }
    }
    return dp[k][n];
}
};
int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++)
          cin>>arr[i];
         int k;
         cin>>k;
        Solution ob;
        cout<<ob.minPages(arr,n,k)<<endl;
    return 0;
}


// Time Complexity: O(k.n^3)
// Space Complexity: o(nk)

// It is better to use Binary Search Approach