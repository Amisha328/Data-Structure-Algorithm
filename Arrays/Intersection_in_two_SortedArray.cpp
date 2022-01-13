// Intersection of two sorted arrays
// Problem Statement:
// Given two sorted arrays, find the intersection of the two arrays.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n,m;
    cin>>n>>m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < m; i++)
        cin>>b[i];

    for(int i = 0; i < m; i++)
    {
        // to avoid duplicates
        if(i > 0 && b[i] == b[i-1])
        continue;
        for(int j = 0; j < m; j++)
        {
            if(a[i] == b[j])
            {
                cout<<a[i]<<" ";
                break;
            }
        }
    }

    
    return 0;
}

// Time Complexity: O(n*m)
// Auxiliary Space: O(1)