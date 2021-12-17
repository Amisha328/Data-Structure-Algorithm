// Problem Statement:
// Given an sorted array of integers, find a pair with sum equal to given sum ‘X’.

// Two pointer Approach

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

    int x;
    cin>>x;

    int f = 0, s = n-1;
    int sum = 0;
    while(f < s)
    {
        sum = v[f] + v[s];
        if(sum == x)
            cout<<v[f]<<" "<<v[s]<<endl;
        // if sum is greater than x, then decrement s as we need to decrease the effect of higher values on sum
        if(sum > x)
            s--;
        else
            f++;
    }
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)