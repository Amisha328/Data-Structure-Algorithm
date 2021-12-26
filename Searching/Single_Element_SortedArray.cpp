// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. 
// Find this single element that appears only once.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
         cin>>v[i];

    int l = 0, h = n-1, ans = -1;
    while(l <= h)
    {
        int mid = (l+h)/2;
        if(mid%2 == 0)
        {
            if(v[mid] == v[mid+1])
                l = mid+2;
            else
            {
                ans = v[mid];
                h = mid-1;
            }
        }
        else
        {
            if(v[mid] == v[mid-1])
                l = mid+1;
            else
            {
                ans = v[mid];
                h = mid-1;
            }
        }
    }
    cout<<ans;
    return 0;
}

// Time Complexity: O(log n)
// Auxiliary Space: O(1)