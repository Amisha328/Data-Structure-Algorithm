// You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] without any duplicates. 
// You are allowed to swap any two elements. Find the minimum number of swaps required to sort the array in ascending order.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++)
    cin>>a[i];

    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++)
    {
        v[i] = {a[i],i};
    }

    sort(v.begin(),v.end());
    // for(int i = 0 ; i < n; i++)
    // {
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i].second != i)
        {
            ans++;
            swap(v[i],v[v[i].second]);
            i--;
        }
    }
    cout<<ans;
    return 0;
}

// Time Complexity: O(n*log(n))
// Auxiliary Space: O(n)