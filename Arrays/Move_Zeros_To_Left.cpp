// Problem Statement:
// Move all zeros to the left of an array while maintaining its order.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0;i<n;i++)
        cin>>v[i];

    int i = n-1;
    int j = n-1;

    while(i>=0){
        if(v[i]!=0){
            v[j--]=v[i];
        }
        i--;
    }

    while(j>=0){
        v[j--]=0;
    }

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)