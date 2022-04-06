// Maximize The Cut Segments
// Problem Statement: https://www.geeksforgeeks.org/maximize-the-number-of-segments-of-length-p-q-and-r/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    // DP - Memoization
    int dp[10001];
    int maxCut(int i, int x, int y, int z)
    {
        if(i == 0)
            return 0;
            
        if(dp[i] != -1)
            return dp[i];
        
        int a,b,c;
        a = b = c = INT_MIN;
        if(x <= i)
            a = maxCut(i-x, x, y, z);
        if(y <= i)
            b = maxCut(i-y, x, y, z);
        if(z <= i)
            c = maxCut(i-z, x, y, z);
            
        int ans = 1 + max({a, b, c});
        
        return dp[i] = ans;
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp, -1, sizeof(dp));
        int ans = maxCut(n, x, y, z);
        if(ans < 0) return 0;
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends