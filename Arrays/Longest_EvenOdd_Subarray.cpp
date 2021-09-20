// Longest Even Odd Subarray
// Find the length of the longest subarray that has alternating even odd elements.

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

    int ans = 0, c = 1;
    for(int i = 0; i < n; i++)
    {
        if((v[i]%2 == 0 && v[i+1] %2 != 0) || (v[i]%2 != 0 && v[i+1] %2 == 0))
             c++;
        else
        {
            ans = max(ans, c);
            c = 1;
        }  
    }
    cout<<ans;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)