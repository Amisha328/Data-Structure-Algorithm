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

    // Method 1: Using set
    set<int> s;
    for(auto &it : v)
    {
        if(s.find(it) == s.end())
            s.insert(it);
    }

    for(auto &it : s)
        cout<<it<<" ";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)