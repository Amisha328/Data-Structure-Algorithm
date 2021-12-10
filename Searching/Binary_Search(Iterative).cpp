
#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int findPos(vi &v, int k)
{
    int n = v.size();
    int l = 0, r = n-1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(v[mid] == k)
            return mid;
        else if(v[mid] < k)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}
signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    
    int k;
    cin>>k;
    
    cout<<findPos(v, k);
    return 0;
}

// Time Complexity: 
// O(log(n)) for successful seach and theta(log(n)) for unsuccessful search.
// Auxiliary Space: O(1)