// Minimum Consecutive Flips
// Given a binary array, we need to find the minimum of number of group flips to make all array elements same. 
// In a group flip, we can flip any set of consecutive 1s or 0s.

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


    for(int i = 1; i < n; i++)
    {
        if(v[i] != v[i-1])
        {
            if(v[i] != v[0])
                cout<<i<<" ";
            else
                cout<<i-1<<" ";
        }
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)