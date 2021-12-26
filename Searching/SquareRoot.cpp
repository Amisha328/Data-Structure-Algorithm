// Square root
// Given an integer, we need to find floor of its square root.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vi vector<int>

ll sqRoot(int n)
{
    ll l = 1, h = n;
    ll ans = 0;
    while(l <= h)
    {
        ll mid = (l+h)/2;
        if((mid*mid) == n)
          return mid;
        else if((mid*mid) > n)
           h = mid-1;
        else
        {
            l = mid+1;
            ans = mid;
        }
            
    }
    return (int)floor(ans);
}
signed main(){
    eff;
    int n;
    cin>>n;

    cout<<sqRoot(n);
    return 0;
}

// Time Complexity: O(log n)
// Auxiliary Space: O(1)