// Problem Statement:
// Calculate the largest possible sum of a sequence of consecutive values in the array.

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

        // Kadane's algorithm
        int sum = v[0], max_val = v[0];
        for(int i = 1; i < n; i++)
        {
            sum = max(v[i], sum + v[i]); // extend the previous max or take the current value
            max_val = max(max_val,sum);
        }

    cout<<max_val;

    return 0;

}   

// Time complexity : O(n)
// Space complexity : O(1)