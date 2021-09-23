// Form a prefix sum array and print the sum from index l to r in O(1) time.

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

    vi prefix_sum(n);
    prefix_sum[0] = v[0];
    for(int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i-1] + v[i]; 

    int l, r;
    cin>>l>>r;
    if(l!=0)
        cout<<prefix_sum[r] - prefix_sum[l-1];
    else
        cout<<prefix_sum[r];
    return 0;
}

// Auxiliary space: O(n)