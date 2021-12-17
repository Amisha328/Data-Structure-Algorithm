// Find a Peak Element
// Problem Statement:
// Given an array of integers, find a peak element in it. An array element is peak if it is NOT smaller than its neighbors. 
// For corner elements, we need to consider only one neighbor. 
// For example, for input array {5, 10, 20, 15}, 20 is the only peak element.

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

    int l = 0, r = n-1;
    
    if(n == 1)
        cout<<v[0];

    while(l <= r)
    {
        int mid = (l+r)/2;
        if((mid == 0 || v[mid] > v[mid-1]) && (mid == n-1 || v[mid] > v[mid+1]))
            cout<<v[mid]<<" ";
        if(mid > 0 && v[mid] < v[mid+1])  
            l = mid+1;
        else
            r = mid-1;
    }
    return 0;
}

// Time Complexity: O(log n)
// Auxiliary Space: O(1)