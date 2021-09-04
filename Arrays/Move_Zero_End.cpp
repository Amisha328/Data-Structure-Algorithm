// The problem of moving all zeros to end keeping the order of remaining elements.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    // Approach: swap every zero element with next non-zero element

    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] != 0)
        {
            swap(v[i], v[res]);
            res++;
        }
    }

    for(int i = 0; i < n; i++)
    {   
        cout<<v[i]<<" ";
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)