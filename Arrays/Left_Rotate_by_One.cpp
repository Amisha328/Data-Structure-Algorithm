// Left Rotate an Array by One
// exampel:
// Input: [1,2,3,4,5]       
// Output: [2,3,4,5,1]

// example2:
// Input: [1,2,3,4,5,6,7]
// Output: [2,3,4,5,6,7,1]

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

    for(int i = 0; i < n-1; i++)
    {
        swap(v[i],v[i+1]);
    }    

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}