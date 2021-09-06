// Maximum Difference Problem with Order
// Maximum Difference problem is to find the maximum of arr[j] - arr[i] where j>i.

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

    int res = v[1] - v[0];
    int min_val = v[0];

    for(int i = 1; i < n; i++)
    {
        res = max(res, v[i]-min_val);
        min_val = min(min_val,v[i]); // min the subtracted value higher is the diff
    }    

    cout<<res;
    return 0;

}   

// Time complexity: O(n)
// Space complexity: O(1)