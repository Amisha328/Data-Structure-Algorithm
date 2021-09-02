#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    for(int i = 0; i < n/2; i++){
        swap(v[i],v[n-i-1]);
    }    

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)